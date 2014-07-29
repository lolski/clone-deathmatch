#include <irrlicht.h>
#include <string>
#include "Human.h"
#include "GameManager.h"
#include "config.h"
#include "ID.h"
#include "Bot.h"

Human::Human() {
    //init();
}

Human::Human(ITriangleSelector *worldTriangleData) {
    //init();
    setWorldTriangleData(worldTriangleData);
}

void Human::update() {
    if (health <= 0) {
        vector3df spawnAt = levelAi->waypoint[(*spawnPoints)[spawnPointIndex].first].position;
        spawn(spawnAt);
        spawnPointIndex = (spawnPointIndex + 1) % spawnPoints->size();
    }
    if (isShooting) {
        shoot();
    }
}

void Human::init() {
    isShooting = false;
    fpsKeymap[0].Action = EKA_MOVE_FORWARD;
    fpsKeymap[0].KeyCode = KEY_KEY_W;
    fpsKeymap[1].Action = EKA_MOVE_BACKWARD;
    fpsKeymap[1].KeyCode = KEY_KEY_S;
    fpsKeymap[2].Action = EKA_STRAFE_LEFT;
    fpsKeymap[2].KeyCode = KEY_KEY_A;
    fpsKeymap[3].Action = EKA_STRAFE_RIGHT;
    fpsKeymap[3].KeyCode = KEY_KEY_D;
    fpsKeymap[4].Action = EKA_JUMP_UP;
    fpsKeymap[4].KeyCode = KEY_SPACE;

    health = 0;
    
    this->worldTriangleData = worldTriangleData;
    bulletNode = NULL;
    
    spawnPointIndex = 2;
    
    playerAndMapRootSceneNode = GM::smgr->getSceneNodeFromName("playerAndMapRootSceneNode");
    camera = GM::smgr->addCameraSceneNodeFPS(playerAndMapRootSceneNode, 100.0f, 1.f, 0, fpsKeymap, 5);
    camera->setName("humanPlayerCameraSceneNode");
    boundingBox = GM::smgr->addCubeSceneNode(20.f, camera, PLAYER_SCENENODE_ID);
    boundingBox->setName("humanPlayerBoundingBoxSceneNode");
    boundingBox->setScale(vector3df(0.9, 3.4, 0.9));
    boundingBox->setPosition(vector3df(0, -17, 0));
    boundingBox->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
    boundingBox->setDebugDataVisible(EDS_BBOX_ALL);
    ITriangleSelector *boundingBoxTri = GM::smgr->createTriangleSelectorFromBoundingBox(boundingBox);
    boundingBox->setTriangleSelector(boundingBoxTri);
    
    irr::core::list<ISceneNodeAnimator *> animators = camera->getAnimators();
    fpsAnimator = *(animators.getLast());
    irr::scene::ISceneNodeAnimatorCameraFPS *fpsAnimatorPtr = static_cast<irr::scene::ISceneNodeAnimatorCameraFPS *> (fpsAnimator);
    fpsAnimatorPtr->setMoveSpeed(fpsAnimatorPtr->getMoveSpeed() / 6);
    standingEllipsoid = irr::core::vector3df(30, 39, 30);
    crouchingEllipsoid = irr::core::vector3df(30, 19, 30);
    irr::core::vector3df gravity(0, -9, 0);
    worldCollision = GM::smgr->createCollisionResponseAnimator(worldTriangleData, camera, standingEllipsoid, gravity, irr::core::vector3df(0, 27, 0));
    camera->addAnimator(worldCollision);
    worldCollision->drop();

}

void Human::spawn(irr::core::vector3df initPos) {
    camera->setPosition(initPos);
    worldCollision->setTargetNode(camera);
    health = 100;
    
}
void Human::crouch() {
    //worldCollision->setEllipsoidRadius(crouchingEllipsoid);
    std::cout<<"crouch";
}

void Human::stand() {
    std::cout<<"stand";//worldCollision->setEllipsoidRadius(standingEllipsoid);
}

irr::scene::ISceneNode *Human::shoot() {
    // recoil
    irr::core::vector3df camtarget = camera->getTarget(); 
    float xForce = recoilForce.getRandom(true);
    float yForce = recoilForce.getRandom(false);
    camtarget.Y+= xForce; // 0.07;
    camtarget.X += yForce; //0.02;
    
    camera->setTarget(camtarget);
    
    irr::scene::ISceneNode *target = NULL;
    if (!bulletNode) {
        bulletNode = GM::smgr->addBillboardSceneNode();
        bulletNode->setID(ENTITY_SCENENODE_CLASS);
        bulletNode->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
        bulletNode->setMaterialTexture(0, GM::vdri->getTexture(PARTICLE_BULLET));
        bulletNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        bulletNode->setSize(irr::core::dimension2df(20.0f, 20.0f));
    }
    if (mp5.clipCapacity == 0) {
        mp5.reload();
    }
    if (!mp5.isReloading) {
        int currentShot = mp5.timer->getTime();
        if (currentShot - mp5.rateOfFire > mp5.lastShot) {
            boundingBox->setIsDebugObject(true);
            target = GM::smgr->getSceneCollisionManager()->getSceneNodeFromCameraBB(getCameraSceneNode(), 0, true);
            boundingBox->setIsDebugObject(false);
            if (target != NULL) {
                if (target->getID() != MAP_SCENENODE_ID) {
                    std::map<ISceneNode *, Bot *>::iterator which = sceneNodeToBotMap->find(target);
                    Bot *b = which->second;
                    if (which != sceneNodeToBotMap->end()) {
                        b->health -= 20;
                    }
                }
            }
            irr::core::line3df bulletPath;
            irr::core::vector3df camPos = camera->getPosition();
            irr::core::vector3df camTarget = camera->getTarget();
            bulletPath.start = camPos;
            bulletPath.end = bulletPath.start + (camTarget - camPos).normalize() * 1000.f;
            bulletNode->setPosition(camera->getPosition() + irr::core::vector3df(0, -100, 0));
            irr::scene::ISceneNodeAnimator *bullet = GM::smgr->createFlyStraightAnimator(bulletPath.start, bulletPath.end, 350);
            bulletNode->addAnimator(bullet);
            
            mp5.lastShot = currentShot;
            mp5.clipCapacity--;
        }
    }
}
void Human::setWorldTriangleData(irr::scene::ITriangleSelector *worldTriangleData) {
    this->worldTriangleData = worldTriangleData;
}

irr::core::vector3d<float> Human::getPosition() const {
    return camera->getPosition();
}

irr::core::vector3d<float> Human::getRotation() const {
    return camera->getRotation();
}

irr::scene::ICameraSceneNode *Human::getCameraSceneNode() const {
    return camera;
}

Human::~Human() {

    // bulletnode drop?
    // bullet drop?
}

