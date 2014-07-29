/* 
 * File:   Waypoint.h
 * Author: lolski
 *
 * Created on October 23, 2012, 3:31 PM
 */

#ifndef WAYPOINT_H
#define	WAYPOINT_H

#include <boost/graph/adjacency_list.hpp>
#include <irrlicht.h>
#include "WaypointNode.h"

using namespace irr;
using namespace irr::core;

typedef boost::adjacency_list<
        boost::listS,
        boost::vecS,
        boost::undirectedS,
        WaypointNode,
        boost::property<boost::edge_weight_t, float> >
    WaypointFreezed;

typedef boost::adjacency_list<
        boost::listS,
        boost::listS,
        boost::undirectedS,
        WaypointNode>
    Waypoint;

typedef Waypoint::vertex_descriptor VertexId;
typedef Waypoint::edge_descriptor EdgeId;
typedef Waypoint::vertex_iterator VertexIt;
typedef Waypoint::edge_iterator EdgeIt;

#endif	/* WAYPOINT_H */

