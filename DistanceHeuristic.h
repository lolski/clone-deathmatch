/* 
 * File:   DistanceHeuristic.h
 * Author: lolski
 *
 * Created on December 9, 2012, 2:05 AM
 */

#ifndef DISTANCEHEURISTIC_H
#define	DISTANCEHEURISTIC_H

#include <ostream>
#include <boost/graph/astar_search.hpp>
#include "Waypoint.h"

template <class Graph>
class DistanceHeuristic : public boost::astar_heuristic<Graph, float> {
public:
    typedef typename boost::graph_traits<Graph>::vertex_descriptor Vertex;
    DistanceHeuristic(Graph &w, Vertex &g):
        waypoint(w),
        goal(g)
    {
        
    }
    float operator()(Vertex v) {
        return 0.f;
    }
private:
    Waypoint &waypoint;
    Vertex &goal;
};
#endif	/* DISTANCEHEURISTIC_H */

