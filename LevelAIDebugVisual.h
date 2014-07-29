/* 
 * File:   LevelAIDebugVisual.h
 * Author: lolski
 *
 * Created on October 23, 2012, 3:03 AM
 */

#ifndef LEVELAIDEBUGVISUAL_H
#define	LEVELAIDEBUGVISUAL_H

#include "Waypoint.h"
#include <irrlicht.h>
#include "GameManager.h"
#include "Waypoint.h"
#include "LevelAIEditor.h"
#include "GenerateUnsignedInt.h"
#include "WaypointNodeType.h"
#include "ID.h"

using namespace irr;
using namespace irr::core;
using namespace irr::scene;

class LevelAIDebugVisual {
public:
    LevelAIDebugVisual() : 
    offset(0, -50, 0) {
        debugMode = false;
        highlightedNode = NULL;
        ISceneNode *globalRootSceneNode = GM::smgr->getRootSceneNode();
        waypointDebugRootNode = GM::smgr->addEmptySceneNode(globalRootSceneNode);
        waypointDebugRootNode->setName("waypointDebugRootNode");
        waypointDebugRootNode->setVisible(false);
    }
    void setWaypointGraph(LevelAIEditor *waypointGraph) {
        this->aiEditor = waypointGraph;
    }
    
    void highlightNode(s32 id) {
        ISceneNode *which = GM::smgr->getSceneNodeFromId(id);
        highlightNode(which);
    }
    void highlightNode(ISceneNode *which) {
         if (highlightedNode != NULL) {
            highlightedNode->setScale(vector3df(1, 1, 1));
        } 
        else {
            
        }
        which->setScale(vector3df(2, 2, 2));
        highlightedNode = which;       
    }
    void createNextNodeConnectedVisualization(s32 id, VertexId newNode) {
        vector3df finalPos = aiEditor->waypoint[newNode].position + offset;
        ISceneNode *cube = GM::smgr->addCubeSceneNode(10.f, waypointDebugRootNode, id, finalPos);
        highlightNode(cube);
    }
    void drawLines() {
        if (debugMode) {
            EdgeIt startIt, endIt, it;
            boost::tie(startIt, endIt) = boost::edges(aiEditor->waypoint);
            for (it = startIt; it != endIt; ++it) {
                 // add linez
                vector3df from = aiEditor->waypoint[boost::source(*it, aiEditor->waypoint)].position;
                vector3df to = aiEditor->waypoint[boost::target(*it, aiEditor->waypoint)].position;
                irr::video::SMaterial material;
                material.Lighting = false;
                GM::vdri->setTransform(video::ETS_WORLD, irr::core::IdentityMatrix);
                GM::vdri->setMaterial(material);
                GM::vdri->draw3DLine(from + offset, to + offset, irr::video::SColor(255, 220,255,51));           
            }
        }
    }
    void removeNodeVisualization(s32 id) {
        ISceneNode *which = GM::smgr->getSceneNodeFromId(id, waypointDebugRootNode);
        which->remove();
        //which = NULL;
        if (which == highlightedNode) {
            highlightedNode = NULL;
        }
    }
    void toggleDebugMode() {
        debugMode = !debugMode;
        if (!debugMode) {
            waypointDebugRootNode->setVisible(false);
        }
        else {
            waypointDebugRootNode->setVisible(true);
        }
    }
    void addSpawnPointFX(ISceneNode *parent) {
        // draw
        IParticleSystemSceneNode *spawnFX = GM::smgr->addParticleSystemSceneNode(false, parent);
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

        //spawnFX->setPosition(position);
        spawnFX->setScale(core::vector3df(2,1,2));
        spawnFX->setMaterialFlag(video::EMF_LIGHTING, false);
        spawnFX->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
        spawnFX->setMaterialTexture(0, GM::vdri->getTexture(SPAWN_POINT_PLAYER));
        spawnFX->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);
    }
    void addCampPointFX(ISceneNode *parent, vector3df orient) {
        IParticleSystemSceneNode *spawnFX = GM::smgr->addParticleSystemSceneNode(false, parent);
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

        //spawnFX->setPosition(position);
        spawnFX->setScale(core::vector3df(2,1,2));
        spawnFX->setMaterialFlag(video::EMF_LIGHTING, false);
        spawnFX->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
        spawnFX->setMaterialTexture(0, GM::vdri->getTexture(SPAWN_POINT_BOT));
        spawnFX->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);        
    }
    void redrawWaypointIndicatorCube() {
        waypointDebugRootNode->removeAll();
        VertexIt vIt, vEndIt, vNextIt;
        boost::tie(vIt, vEndIt) = boost::vertices(aiEditor->waypoint);
        for (vNextIt = vIt; vIt != vEndIt; vIt = vNextIt) {
            int id = generateUnsignedInt();
            int type = aiEditor->waypoint[*vIt].type;
            vector3df position = aiEditor->waypoint[*vIt].position + offset;
            ISceneNode *node = GM::smgr->addCubeSceneNode(10.f, waypointDebugRootNode, id, position);
            if (type == GOAL_ROAM) {
                node->setScale(vector3df(1, 4, 1));
            }
            else if (type == CAMP) {
                ISceneNode *player = GM::smgr->getSceneNodeFromId(999);
                vector3df orient = player->getRotation();
                orient.X *= -1; // invert orientation by Y axis
                orient.Z *= -1; // invert orientation by Y axis
                addCampPointFX(node, orient);
            }
            else if (type == SPAWN_POINT) {
                addSpawnPointFX(node);
            }
            aiEditor->waypointAsVertexMap.insert(std::pair<s32, VertexId>(id, *vIt));
            ++vNextIt;
        }
    }
    ~LevelAIDebugVisual() {
        //delete selectedNode;
    }
    irr::scene::ISceneNode *waypointDebugRootNode;
private:
    bool debugMode;
    ISceneNode *highlightedNode;
    LevelAIEditor *aiEditor;
    vector3df offset;
};

#endif	/* LEVELAIDEBUGVISUAL_H */

