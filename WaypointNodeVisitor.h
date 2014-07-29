/* 
 * File:   WaypointNodeVisitor.h
 * Author: lolski
 *
 * Created on December 9, 2012, 2:19 AM
 */

#ifndef WAYPOINTNODEVISITOR_H
#define	WAYPOINTNODEVISITOR_H

#include <boost/graph/astar_search.hpp>
#include "Waypoint.h"
#include "GoalFoundTermination.h"

template <class Vertex>
class WaypointNodeVisitor: public boost::default_astar_visitor {
public:
    WaypointNodeVisitor(Vertex v): goal(v) {}
    template <class Graph>
    void examine_vertex(Vertex v, Graph &g) {
        if (v == goal) {
            throw GoalFoundTermination();
        }
    }
private:
    Vertex goal;
};

#endif	/* WAYPOINTNODEVISITOR_H */

