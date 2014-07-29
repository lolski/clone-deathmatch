/* 
 * File:   SpawnPointDebug.h
 * Author: lolski
 *
 * Created on October 22, 2012, 7:32 PM
 */

#ifndef SPAWNPOINTDEBUG_H
#define	SPAWNPOINTDEBUG_H

#include "SpawnPointCollection.h"
#include <irrlicht.h>
#include "GameManager.h"
#include "config.h"
#include <vector>
#include "ID.h"

using namespace irr;
using namespace irr::scene;

class SpawnPointDebug {
public:
    SpawnPointDebug(){
        debugMode = false;
        ISceneNode *globalRootSceneNode = GM::smgr->getRootSceneNode();
        spawnPointDebugSceneNode = GM::smgr->addEmptySceneNode(globalRootSceneNode, CONTAINER_SCENENODE_CLASS | DEBUG_SCENENODE_CLASS);
        spawnPointDebugSceneNode->setName("spawnPointDebugRootNode");
    }
    IParticleSystemSceneNode *addBotSpawnPointFX(vector3df position) {
        // draw
        IParticleSystemSceneNode *spawnFX = GM::smgr->addParticleSystemSceneNode(false, spawnPointDebugSceneNode, DEBUG_SCENENODE_CLASS | 2);
        IParticleEmitter *emitter = spawnFX->createBoxEmitter(
            core::aabbox3d<f32>(-3,0,-3,3,0.3,3), // emitter size
            core::vector3df(0.0f,0.06f,0.0f),   // initial direction
            10,80,                             // emit rate
            video::SColor(0,0,0,0),       // darkest color
            video::SColor(0,255,255,255),       // brightest color
            800,2000,0,                         // min and max age, angle
            core::dimension2df(1.f,1.f),      // min size
            core::dimension2df(5.f,5.f)       // max size
        );
        spawnFX->setEmitter(emitter);
        emitter->drop();
        IParticleAffector *affector = spawnFX->createFadeOutParticleAffector();
        spawnFX->addAffector(affector);
        affector->drop();

        spawnFX->setPosition(position);
        spawnFX->setScale(core::vector3df(2,1,2));
        spawnFX->setMaterialFlag(video::EMF_LIGHTING, false);
        spawnFX->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
        spawnFX->setMaterialTexture(0, GM::vdri->getTexture(SPAWN_POINT_BOT));
        spawnFX->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);   
        return spawnFX;
    }
    IParticleSystemSceneNode *addSpawnPointFX(vector3df position) {
        // draw
        IParticleSystemSceneNode *spawnFX = GM::smgr->addParticleSystemSceneNode(false, spawnPointDebugSceneNode, DEBUG_SCENENODE_CLASS);
        IParticleEmitter *emitter = spawnFX->createBoxEmitter(
            core::aabbox3d<f32>(-3,0,-3,3,0.3,3), // emitter size
            core::vector3df(0.0f,0.06f,0.0f),   // initial direction
            10,80,                             // emit rate
            video::SColor(0,0,0,0),       // darkest color
            video::SColor(0,255,255,255),       // brightest color
            800,2000,0,                         // min and max age, angle
            core::dimension2df(1.f,1.f),      // min size
            core::dimension2df(5.f,5.f)       // max size
        );
        spawnFX->setEmitter(emitter);
        emitter->drop();
        IParticleAffector *affector = spawnFX->createFadeOutParticleAffector();
        spawnFX->addAffector(affector);
        affector->drop();

        spawnFX->setPosition(position);
        spawnFX->setScale(core::vector3df(2,1,2));
        spawnFX->setMaterialFlag(video::EMF_LIGHTING, false);
        spawnFX->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
        spawnFX->setMaterialTexture(0, GM::vdri->getTexture(SPAWN_POINT_PLAYER));
        spawnFX->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);
        return spawnFX;
    }
    void toggleDebugMode() {
        debugMode = !debugMode;
        if (!debugMode) {
            spawnPointDebugSceneNode->setVisible(false);
        }
        else {
            spawnPointDebugSceneNode->setVisible(true);
        }
    }
    bool debugMode;
    ISceneNode *spawnPointDebugSceneNode;
private:

};

#endif	/* SPAWNPOINTDEBUG_H */

