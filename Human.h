/* 
 * File:   Human.h
 * Author: lolski
 *
 * Created on September 3, 2009, 3:35 AM
 */

#ifndef _HUMAN_H
#define	_HUMAN_H

#include <vector>
#include <irrlicht.h>
#include "debug.h"
#include "RandomNumberCollection.h"
#include "Weapon.h"
#include "WaypointNode.h"
#include "LevelAIEditor.h"
#include "LevelAITypes.h"

using namespace irr;
using namespace irr::core;
using namespace irr::scene;

class Bot;

class Human {
public:
    Human();
    Human(ITriangleSelector *worldTriangleData);
    void spawn(vector3df initPos = vector3df(0, 10, 0));
    void update();
    ISceneNode *shoot();
    void crouch();
    void stand();
    void jump();
    void setWorldTriangleData(ITriangleSelector *worldTriangleData);
    void setSpawnPoints(std::vector<WaypointNode> *spawnPoints);
    vector3df getPosition() const;
    vector3df getRotation() const;
    ICameraSceneNode *getCameraSceneNode() const;
    void init();
    void toggleWeapon();
    virtual ~Human();
    bool isShooting;
    int health;
    LevelAIEditor *levelAi;
    SpawnPointVector *spawnPoints;
    std::map<ISceneNode *, Bot *> *sceneNodeToBotMap;
    ISceneNode *boundingBox;
private:
    Weapon mp5;
    ICameraSceneNode *camera;
    ISceneNode *playerAndMapRootSceneNode;
    ISceneNodeAnimator *fpsAnimator;
    ISceneNodeAnimatorCollisionResponse *worldCollision;
    ITriangleSelector *worldTriangleData;
    vector3df crouchingEllipsoid;
    vector3df standingEllipsoid;
    SKeyMap fpsKeymap[5];
    IBillboardSceneNode *bulletNode;
    RandomNumberCollection recoilForce;
    int spawnPointIndex;
};

#endif	/* _HUMAN_H */