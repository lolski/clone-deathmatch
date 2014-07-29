/* 
 * File:   BotLogic.h
 * Author: lolski
 *
 * Created on October 26, 2012, 4:20 AM
 */


#ifndef BOTLOGIC_H
#define	BOTLOGIC_H

#include "DistanceHeuristic.h"
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/astar_search.hpp>
#include "Goal.h"
#include "LevelAIEditor.h"
#include "Pathfinding.h"

class BotLogic {
public:
    BotLogic(irr::scene::ITriangleSelector *worldTriangleData, LevelAIEditor *levelAi): pathfinding(*levelAi) {
        this->levelAi = levelAi;
        nextPoint = 0;
        pathfinding.updateIndexMap();
    }
    void changeGoal() {
        // astar
        //pVec3d(levelAi->waypoint[levelAi->roamPoints[nextPoint]].position, "next goal");
        pathToCurrentGoal.clear();
        pathToCurrentGoal = pathfinding.calculatePathFrom(currentNode, levelAi->roamPoints[nextPoint]);
        
        // store the list of path
        nextPoint = (nextPoint + 1) % levelAi->roamPoints.size();
    }
    
    void fight(); // shoot, jump, move around, crouch
    void flee();
    void camp();
    void learn(); // mark which area is dangerous (increase graph weight around parts where it died)
    
    irr::core::vector3df currentPosition;
    
    Pathfinding pathfinding;
    VertexId currentNode;
    std::deque<VertexId> pathToCurrentGoal;
    // map data
    irr::scene::ITriangleSelector* worldTriangleData;
    LevelAIEditor *levelAi;
private:
    int nextPoint;
};

#endif	/* BOTLOGIC_H */

