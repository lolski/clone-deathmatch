#include "Bot.h"
#include "Human.h"
#include "ID.h"
#include "PrintSceneNodeImmediateChildren.h"

Bot::Bot(irr::scene::ITriangleSelector *worldTriangleSelector, LevelAIEditor *levelAi) :
        mvspeed(130, 0, 130),
        logic(worldTriangleSelector, levelAi),
        currentHumanEnemy(NULL),
        currentBotEnemy(NULL), health(0) {
    logic.levelAi = levelAi;
    waypoint = &(levelAi->waypoint);
    logic.worldTriangleData = worldTriangleSelector;
    playerAndMapRootSceneNode = GM::smgr->getSceneNodeFromName("playerAndMapRootSceneNode");
    debugMode = false;
}

void Bot::OnAnimationEnd(IAnimatedMeshSceneNode *node) {
    if (currentAnimation == DEATH) {
        head->setLoopMode(true);
        handleRespawnEvent();
    }
}

void Bot::init() {
    node = GM::smgr->addEmptySceneNode(playerAndMapRootSceneNode);
    node->setName("botNodeSceneNode");
    mesh = GM::smgr->getMesh(MODEL_NAME);
    head = GM::smgr->addAnimatedMeshSceneNode(mesh, node);
    head->setName("botHeadSceneNode");
    head->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    head->setMaterialTexture(0, GM::vdri->getTexture(MODEL_TEXTURE));
    head->setAnimationEndCallback(this);
    triangles = GM::smgr->createTriangleSelector(mesh, head);
    head->setTriangleSelector(triangles);
    vision = GM::smgr->addCubeSceneNode(30);
    vision->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
    vision->setName("botVisionSceneNode");
    vision->setPosition(vector3df(400, 0, 0));
    vision->setScale(vector3df(30, 5, 10));
    vision->setIsDebugObject(true);
    head->addChild(vision);
    
    vector3df standingEllipsoid(30, 39, 30);
    vector3df gravity(0, -9 , 0);
    worldCollision = GM::smgr->createCollisionResponseAnimator(logic.worldTriangleData, head, standingEllipsoid, gravity, irr::core::vector3df(0, 10, 0));
    node->addAnimator(worldCollision);
    
    head->setMD2Animation(EMAT_STAND);
    currentAnimation = STAND;
    
    bulletNode = GM::smgr->addBillboardSceneNode();
    bulletNode->setVisible(true);
    bulletNode->setID(ENTITY_SCENENODE_CLASS);
    bulletNode->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
    bulletNode->setMaterialTexture(0, GM::vdri->getTexture(PARTICLE_BULLET));
    bulletNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    bulletNode->setSize(irr::core::dimension2df(20.0f, 20.0f));
}
void Bot::spawn(vector3df initPos) {
    node->setPosition(initPos);
    worldCollision->setTargetNode(node);
    health = 100;
    currentAction = ACTION_ROAM;
}

void Bot::update(Human *player, std::list<Bot *> *enemies) {
    if (health <= 0) {
        head->setLoopMode(false);
        if (currentAnimation != DEATH) {
            currentAnimation = DEATH;
            if (spawnPointIndex % 2 == 0) {
                head->setMD2Animation(EMAT_DEATH_FALLBACKSLOW);
            }
            else {
                head->setMD2Animation(EMAT_DEATH_FALLBACK);
            }
        }
    }
    else {
        if (currentAction == ACTION_ROAM) {
            vector3df botPos = node->getPosition();
            //lookAround();
            updateVision(player, enemies);
            // goal reached
            if (botPos.equals(logic.levelAi->waypoint[logic.pathToCurrentGoal.back()].position, 20.f)) {
                // get new goal
                logic.currentNode = logic.pathToCurrentGoal.back();
                logic.changeGoal();
            }
            // getting closer to a goal
            else {
                // track current position
                if (botPos.equals(logic.levelAi->waypoint[logic.pathToCurrentGoal.front()].position, 20.f)) {
                    logic.pathToCurrentGoal.pop_front();
                    logic.currentNode = logic.pathToCurrentGoal.front();
                }
                else {
                    updateMove();
                }
                // if enemy is in sight
            }
        }
        else if (currentAction == ACTION_ATTACK) {
            // attack
            if (currentAnimation != ATTACK) {
                currentAnimation = ATTACK;
                head->setMD2Animation(EMAT_ATTACK);
            }
            updateShoot(currentHumanEnemy, currentBotEnemy);
            if (currentHumanEnemy != NULL) {
                if (currentHumanEnemy->health <= 0) {
                    if (currentAction != ACTION_ROAM) {
                        currentAction = ACTION_ROAM;
                        currentHumanEnemy = NULL;
                    }
                }
            }
            else if (currentBotEnemy != NULL) {
                if (currentBotEnemy->health <= 0) {
                    if (currentAction != ACTION_ROAM) {
                        currentAction = ACTION_ROAM;
                        currentBotEnemy = NULL;
                    }
                }
            }
        }
        else if (currentAction == ACTION_FLEE) {
            // mark 5 close waypoint as very expensive
            // change goal
            updateFlee();
        }
        else if (currentAction == ACTION_CHASE) {
            // get node closest to enemy as goal
            // go
            updateChase();
        }
    }
}

void Bot::updateMove() {
    vector3df source = node->getPosition();
    vector3df target = logic.levelAi->waypoint[logic.pathToCurrentGoal.front()].position;
    vector3df orient = (target - source).normalize();
    vector3df newPos = node->getPosition() + orient * mvspeed * GM::timer.timeFactor;
    // set X and Z to 0 so that it doesn't get tilted when the waypoint is not on the same Y axis level
    // e.g. when from.Y = 0 and to.Y = 13
    vector3df modelOrient = orient.getHorizontalAngle();
    modelOrient.X = 0;
    modelOrient.Y -= 90;
    modelOrient.Z = 0; 
    node->setRotation(modelOrient);
    node->setPosition(newPos);
    //worldCollision->setTargetNode(node);
    if (currentAnimation != RUN) {
        currentAnimation = RUN;
        head->setMD2Animation(EMAT_RUN);
    }
}
void Bot::updateLookAround() {
    static u32 last = 0;
    u32 now = GM::dev->getTimer()->getTime();
    if (now - last > 5000) {
        vector3df rot = head->getRotation();
        rot.Y += 10 * GM::timer.timeFactor;
        if (rot.Y == 360) {    
            last = now;
            rot.Y = 0;
        }
        else {
        }
        
        head->setRotation(rot);
    }
}
void Bot::updateVision(Human *player, std::list<Bot *> *enemies) {
    aabbox3df vis = vision->getTransformedBoundingBox();
    vector3df bpos = node->getPosition();
    vector3df ppos = player->getPosition();
    for (std::list<Bot *>::iterator it = enemies->begin(); it != enemies->end(); ++it) {
        if (*it != this) {
            vector3df anotherBotPos = (*it)->node->getPosition();
            if (vis.isPointInside(anotherBotPos)) {
                ISceneNode *which = isVisibleFrom(bpos, anotherBotPos);
                if (which != NULL) {
                    if (which->getID() != MAP_SCENENODE_ID) {
                        ISceneNode *enemyNode = which;
                        std::map<ISceneNode *, Bot *>::iterator enemyIt = sceneNodeToBotMap->find(enemyNode);
                        if (enemyIt != sceneNodeToBotMap->end()) {
                            currentBotEnemy = enemyIt->second;
                            if (health >= currentBotEnemy->health) {
                                updateShoot(NULL, currentBotEnemy);
                                if (currentBotEnemy->health <= 0) {
                                    if (currentAction != ACTION_ROAM) {
                                        currentAction = ACTION_ROAM;
                                        currentBotEnemy = NULL;
                                    }
                                }
                            }
                            else {
                                updateFlee();
                            }
                        }
                    }
                }
            }
        }
    }
    if (vis.isPointInside(ppos)) {
        ISceneNode *which = isVisibleFrom(bpos, ppos);
        if (which != NULL) {
            if (which->getID() != MAP_SCENENODE_ID) {
                if (which->getID() == PLAYER_SCENENODE_ID) {
                    ISceneNode *playerNode = which; // since which is a mesh, not the node itself
                    std::map<ISceneNode *, Human *>::iterator playerIt = sceneNodeToPlayerMap->find(playerNode);
                    if (playerIt != sceneNodeToPlayerMap->end()) {
                        currentHumanEnemy = playerIt->second;
                        if (health >= currentHumanEnemy->health) {
                            updateShoot(currentHumanEnemy, NULL);
                            if (currentHumanEnemy->health <= 0) {
                                if (currentAction != ACTION_ROAM) {
                                    currentAction = ACTION_ROAM;
                                    currentHumanEnemy = NULL;
                                }
                            }
                        }
                        else {
                            updateFlee();
                        }
                    }
                }
            }
        }
        else {
        }
    }
}
void Bot::updateShoot(Human *one, Bot *two) {
    ISceneNode *target = NULL;
    vector3df targetPos;
    if (one != NULL) {
        target = one->boundingBox;
        targetPos = one->getPosition();
    }
    else if (two != NULL) {
        target = two->node;
        targetPos = two->node->getPosition();
    }
    
    vector3df orient = (targetPos - node->getPosition()).normalize();
    // set X and Z to 0 so that it doesn't get tilted when the waypoint is not on the same Y axis level
    // e.g. when from.Y = 0 and to.Y = 13
    vector3df modelOrient = orient.getHorizontalAngle();
    modelOrient.X = 0;
    modelOrient.Y -= 90;
    modelOrient.Z = 0; 
    node->setRotation(modelOrient);

    if (currentAction != ACTION_ATTACK && currentAnimation != ATTACK) {
        currentAction = ACTION_ATTACK;
        currentAnimation = ATTACK;
        head->setMD2Animation(EMAT_ATTACK);
    }

    if (mp5.clipCapacity == 0) {
        mp5.reload();
    }
    if (!mp5.isReloading) {
        int currentShot = mp5.timer->getTime();
        if (currentShot - mp5.rateOfFire > mp5.lastShot) {
            irr::core::line3df bulletPath;
            bulletPath.start = node->getPosition();
            bulletPath.end = target->getParent()->getPosition();

            // recoil
            float xForce = recoilForce.getRandom(true);
            float yForce = recoilForce.getRandom(false);
            bulletPath.end.Y += xForce * 40; // 0.07
            bulletPath.end.X += yForce * 40; // 0.02
            bulletNode->setPosition(node->getPosition());
            irr::scene::ISceneNodeAnimator *bullet = GM::smgr->createFlyStraightAnimator(bulletPath.start, bulletPath.end, 40);
            bulletNode->addAnimator(bullet);
            mp5.lastShot = currentShot;
            mp5.clipCapacity--;

            if (xForce > 0.009) { //  if it hits the target
                if (one != NULL) {
                    one->health -= 20;
                }
                else if (two != NULL) {
                    two->health -= 20;
                }
            }
        }
    }
}
void Bot::updateFlee() {
    if (currentAction != ACTION_FLEE) {
        currentAction = ACTION_FLEE;
    }
}
void Bot::updateChase() {
    if (currentAction != ACTION_CHASE) {
        currentAction = ACTION_CHASE;
    }
}
void Bot::handleRespawnEvent() {
    VertexId id = (*spawnPoints)[spawnPointIndex].first;
    vector3df spawnAt = (*waypoint)[id].position;
    spawn(spawnAt);
    logic.currentNode = id;
    logic.changeGoal();

    spawnPointIndex = (spawnPointIndex + 1) % spawnPoints->size();
    currentAnimation = STAND;
}

ISceneNode *Bot::isVisibleFrom(vector3df &from, vector3df &to) {
    irr::scene::ISceneCollisionManager *cm = GM::smgr->getSceneCollisionManager();
    line3df rayCollision;
    rayCollision.start = from;
    rayCollision.end = to;
    
    if (debugMode) {
        video::SMaterial material;
        material.Lighting = false;
        GM::vdri->setTransform(video::ETS_WORLD, IdentityMatrix);
        GM::vdri->setMaterial(material);
        GM::vdri->draw3DLine(rayCollision.start + vector3df(0, -5, 0), rayCollision.end + vector3df(0, -5, 0), video::SColor(255, 255,0, 0));
    }
    vector3df collisionPoint;
    triangle3df trianglePoint;
    ISceneNode *which = cm->getSceneNodeAndCollisionPointFromRay(rayCollision, collisionPoint, trianglePoint, testCollisionAgainst, 0, playerAndMapRootSceneNode);
    
    if (debugMode) {
        GM::vdri->draw3DTriangle(trianglePoint, video::SColor(255, 255, 0, 0));
    }
    return which;
}
void Bot::toggleDebugMode() {
    debugMode = !debugMode;
    if (debugMode) {
        vision->setDebugDataVisible(EDS_BBOX_ALL); 
        head->setDebugDataVisible(EDS_BBOX_ALL);
    }
    else {
        vision->setDebugDataVisible(EDS_OFF); 
        head->setDebugDataVisible(EDS_OFF);
    }
    logic.pathfinding.toggleDebugMode();
}
Bot::~Bot() {
    triangles->drop();
    worldCollision->drop();
}

