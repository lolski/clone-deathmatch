/* 
 * File:   LevelAIEditor.h
 * Author: lolski
 *
 * Created on October 23, 2012, 2:26 AM
 */

#ifndef LEVELAIEDITOR_H
#define	LEVELAIEDITOR_H

#include <boost/graph/adj_list_serialize.hpp>
#include <boost/serialization/map.hpp>
//#include <boost/graph/graphviz.hpp>
#include <map>
#include <irrlicht.h>
#include "LevelAIEditor.h"
#include "GetCurrentDateTime.h"
#include "config.h"
#include "Waypoint.h"
#include "WaypointNodeType.h"
#include "DistanceHeuristic.h"
#include "LevelAITypes.h"

using namespace irr;
using namespace irr::core;

class LevelAIEditor {
public:
    LevelAIEditor() {
        lastVertex = NULL;
        nodeStack = NULL;
    }
    void startConnectingProcess(s32 fromId) {        
        if (waypointAsVertexMap.size() > 1) {
            nodeStack = new s32;
            *nodeStack = fromId;
        }
        else {
            std::cerr<<"ERROR: can't start this operation when there is only one node"<<std::endl;
        }
    }
    void finishConnectingProcess(s32 toId) {
        VertexId from, to;
        bool fromFound = findNode(*nodeStack, from);
        bool toFound = findNode(toId, to);
        if (fromFound && toFound) {
            if (from != to) {
               bool status = connectNode(from, to);
               if (status) {
                   cleanupConnectingProcess();
               }
               else {
                   std::cerr<<"ERROR: WaypointGraph::finishConnectingProcess fails when executing connectNode"<<std::endl;
               }               
            }
            else {
                std::cerr<<"ERROR: WaypointGraph::finishConnectingProcess fails because from == to"<<std::endl;
            }

        }
        else {
            std::cerr<<"ERROR: WaypointGraph::finishConnectingProcess fails to find either from or to node"<<std::endl;
        }
    }
    void cancelConnectingProcess() {
        cleanupConnectingProcess();
    }
    bool isInConnectingProcess() {
        bool status;
        if (nodeStack != NULL) {
            status = true;
        }
        else {
            status = false;
        }
        return status;
    }
    bool connectNode(VertexId from, VertexId to) {
        EdgeId newEdge;
        bool status;
        boost::tie(newEdge, status) = boost::add_edge(from, to, waypoint);
        return status;
    }
    VertexId createNextNodeConnected(s32 id, vector3df position) {
        WaypointNode node(position);
        VertexId newVertex = boost::add_vertex(node, waypoint);
        waypointAsVertexMap.insert(std::pair<s32, VertexId>(id, newVertex));
        if (lastVertex != NULL) {
            bool status = connectNode(newVertex, *lastVertex);
            
            if (!status) {
                std::cerr<<"ERROR: adding edges in WaypointGraphDebug.h"<<std::endl;
            }
        }
        else {
            lastVertex = new VertexId;
        }
        selectNode(id);
        
        return newVertex;
    }
    VertexId createNode(s32 id, vector3df position) {
        WaypointNode node(position);
        VertexId newVertex = boost::add_vertex(node, waypoint);
        waypointAsVertexMap.insert(std::pair<s32, VertexId>(id, newVertex));
        return newVertex;
    }
    bool findNode(s32 id, VertexId &outVertex) {
        std::map<s32, VertexId>::iterator whichIt = waypointAsVertexMap.find(id);
        bool ret = false;
        if (whichIt != waypointAsVertexMap.end()) {
            outVertex = whichIt->second;
            ret = true;
        }
        return ret;
    }
    void selectNode(s32 id) {
        VertexId selected;
        if (findNode(id, selected)) {
            if (lastVertex == NULL) {
                lastVertex = new VertexId;
            }
            *lastVertex = selected;
        }
        else {
            std::cerr<<"ERROR: unable to select non-existent node id:"<<id<<std::endl;
            delete lastVertex;
            lastVertex = NULL;
        }
    }
    void removeNode(s32 id) {
        VertexId which;
        if (findNode(id, which)) {
            size_t numOfErasedElem = waypointAsVertexMap.erase(id);
            if (numOfErasedElem) {
                boost::clear_vertex(which, waypoint);
                boost::remove_vertex(which, waypoint);
                selectNode(id); 
                //delete lastVertex;
                //lastVertex = NULL;
            }
            else {
                std::cerr<<"ERROR: inconsistent state between waypoint and waypointVertexMap: element is inside waypoint but not inside waypointVertexMap"<<std::endl;
            }
        }
        else {
            std::cerr<<"ERROR: removal of non-existing node id: "<<id<<std::endl;
        }
    }
    void changeNodeType(s32 id, WaypointNodeType type) {
        VertexId which;
        bool found = findNode(id, which);
        if (found) {
            waypoint[which];
        }
        else {
            std::cerr<<"error: can't change node type - no node selected"<<std::endl;
        }
    }
    void updateWaypointCache() {
        VertexIt startIt, endIt;
        boost::tie(startIt, endIt) = boost::vertices(waypoint);
        for (VertexIt it = startIt; it != endIt; ++it) {
            WaypointNodeType type = waypoint[*it].type;
            if (type == GOAL_ROAM) {
                roamPoints.push_back(*it);
            }
            else if (type == SPAWN_POINT) {
                spawnPoints.push_back(std::pair<VertexId, bool>(*it, true));
            }
            else if (type == CAMP) {
                campPoints.push_back(*it);
            }
        }
    }
    void dumpImage() {
        //std::ofstream dotfile(GRAPHVIZ_DUMP);
        //boost::write_graphviz(dotfile, waypoint);
    }
    ~LevelAIEditor() {
        //std::string filename = giveMeTheCurrentDateTimePlease();
    }
    Waypoint waypoint;
    std::map<s32, VertexId> waypointAsVertexMap;
    SpawnPointVector spawnPoints;
    std::vector<VertexId> roamPoints;
    std::vector<VertexId> campPoints;
private:
    void cleanupConnectingProcess() {
        delete nodeStack;
        nodeStack = NULL;
    }
    VertexId *lastVertex;
    s32 *nodeStack;
};

#endif	/* LEVELAIEDITOR_H */

