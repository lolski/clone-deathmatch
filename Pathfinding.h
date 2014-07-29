/* 
 * File:   Pathfinding.h
 * Author: lolski
 *
 * Created on December 9, 2012, 2:38 AM
 */

#ifndef PATHFINDING_H
#define	PATHFINDING_H

#include <boost/graph/astar_search.hpp>
#include <irrlicht.h>
#include "LevelAIEditor.h"
#include "Waypoint.h"
#include "WaypointNodeVisitor.h"
#include "GoalFoundTermination.h"
#include "AStarPropertyType.h"

using namespace irr;
using namespace irr::scene;

class Pathfinding {
public:
    Pathfinding(LevelAIEditor &levelAi):
        waypoint(levelAi.waypoint),
        vertexIndexMap(indexMap),
        edgeWeightMap(weightMap),
        vertexPredecessorMap(predecessorMap)
    {
        irr::scene::ISceneNode *globalRootSceneNode = GM::smgr->getRootSceneNode();
        pathfindingDebugRootNode = GM::smgr->addEmptySceneNode(globalRootSceneNode);
        pathfindingDebugRootNode->setName("pathfindingDebugRootNode");
        pathfindingDebugRootNode->setVisible(false);
        debugMode = false;
    }
    void updateIndexMap() {
        size_t i=0;
        BGL_FORALL_VERTICES(v, waypoint, Waypoint) {
            put(vertexIndexMap, v, i++);
        }
        BGL_FORALL_EDGES(e, waypoint, Waypoint) {
            put(edgeWeightMap, e, 1);
        }
    }
    std::deque<VertexId> calculatePathFrom(VertexId start, VertexId goal) {
        std::deque<VertexId> shortestPath;
        vector3df s = waypoint[start].position;
        vector3df g = waypoint[goal].position;

        try {
            boost::astar_search(waypoint, start, DistanceHeuristic<Waypoint>(waypoint, goal),
                boost::visitor(WaypointNodeVisitor<VertexId>(goal)).vertex_index_map(vertexIndexMap).weight_map(edgeWeightMap).predecessor_map(vertexPredecessorMap));
        }
        catch (GoalFoundTermination found) {
            VertexId v = goal;
            pathfindingDebugRootNode->removeAll();
            for (VertexId v = goal;; v = vertexPredecessorMap[v]) {
                if(vertexPredecessorMap[v] == v) break;
                else {
                    shortestPath.push_front(v);
                    highlightPathDebugVisual(pathfindingDebugRootNode, waypoint[v].position);
                }
            }
            shortestPath.push_back(goal);
        }
        return shortestPath;
    }
    void highlightPathDebugVisual(ISceneNode *parent, vector3df position) {
        IParticleSystemSceneNode *spawnFX = GM::smgr->addParticleSystemSceneNode(false, parent);
        position.Y -= 20;
        spawnFX->setPosition(position);
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
    void toggleDebugMode() {
        debugMode = !debugMode;
        if (debugMode) {
            pathfindingDebugRootNode->setVisible(true);
        }
        else {
            pathfindingDebugRootNode->setVisible(false);
        }
    }
    Waypoint &waypoint;
    IndexMap indexMap;
    WeightMap weightMap;
    PredecessorMap predecessorMap;
    boost::associative_property_map<IndexMap> vertexIndexMap;
    boost::associative_property_map<WeightMap> edgeWeightMap;
    boost::associative_property_map<PredecessorMap> vertexPredecessorMap;
    
    irr::scene::ISceneNode *pathfindingDebugRootNode;
    bool debugMode;
};

#endif	/* PATHFINDING_H */

