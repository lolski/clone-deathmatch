/* 
 * File:   Bot.h
 * Author: lolski
 *
 * Created on August 21, 2009, 12:35 AM
 */

#ifndef _BOT_H
#define	_BOT_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <irrlicht.h>
#include "debug.h"
#include "config.h"
#include "GameManager.h"
#include "BotLogic.h"
#include "LevelAITypes.h"
#include "Human.h"

enum Animation { STAND, ATTACK, RUN, PAIN, DEATH, CROUCH };

class Bot : public IAnimationEndCallBack {
public:
    Bot();
    Bot(ITriangleSelector *worldTriangleData, LevelAIEditor *levelAi);
    virtual void OnAnimationEnd(IAnimatedMeshSceneNode *node);
    void init();
    void spawn(vector3df initPos = vector3df(0, 0, -30));
    void handleRespawnEvent();
    ISceneNode *isVisibleFrom(vector3df &from, vector3df &to);
    
    void update(Human *player, std::list<Bot *> *enemies);
    void updateMove(); // must be invoked within update
    void updateLookAround();
    void updateVision(Human *player, std::list<Bot *> *enemies); // check if there is enemy within sight
    void updateShoot(Human *one, Bot *two);
    void updateFlee();
    void updateChase();
    void toggleDebugMode();
    virtual ~Bot();

    // core logic
    BotLogic logic;
    int health;
    Waypoint *waypoint;
    SpawnPointVector *spawnPoints;
    int spawnPointIndex;
    // collision, aiming target system, etc
    enum Action { ACTION_ATTACK, ACTION_ROAM, ACTION_FLEE, ACTION_CHASE };
    Action currentAction;
    ISceneNodeAnimatorCollisionResponse *worldCollision;
    ISceneNode *playerAndMapRootSceneNode;
    s32 id;
    s32 testCollisionAgainst;
    std::map<ISceneNode *, Bot *> *sceneNodeToBotMap;
    std::map<ISceneNode *, Human *> *sceneNodeToPlayerMap;
    Weapon mp5;
    Human *currentHumanEnemy;
    Bot *currentBotEnemy;
    RandomNumberCollection recoilForce;
    
    // graphic
    ISceneNode *node, *vision;
    IAnimatedMeshSceneNode *head;
    ITriangleSelector *triangles;
    IAnimatedMesh *mesh;
    IBillboardSceneNode *bulletNode;
    vector3df mvspeed;
    enum Animation { STAND, ATTACK, RUN, PAIN, DEATH, CROUCH };
    Animation currentAnimation;
    
    // catmull-rom parameters
    irr::u32 currTime, prevTime;
    s32 P0, P1, P2, P3;
    u32 RunCount;// e.g. for 10 points, there are 9 segments to transverse: RunCount=9
    bool IsSplineStarted;
    bool IsSplineEnded;
    irr::f32 SplineElapsedTime;
    
    bool debugMode;
    
};

#endif	/* _BOT_H */