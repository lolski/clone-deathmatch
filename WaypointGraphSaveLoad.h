/* 
 * File:   WaypointGraphSaveLoad.h
 * Author: lolski
 *
 * Created on December 6, 2012, 1:02 AM
 */

#ifndef WAYPOINTGRAPHSAVELOAD_H
#define	WAYPOINTGRAPHSAVELOAD_H

#include <fstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/iteration_macros.hpp>
#include <irrlicht.h>
#include "LevelAIEditor.h"
#include "Serialize.h"

void loadWaypointGraph(LevelAIEditor &waypoint, const char *path) {
    std::ifstream instream(path);
    boost::archive::text_iarchive inarchive(instream);
    waypoint.waypoint.clear();
    inarchive >> waypoint;
}
void saveWaypointGraph(const LevelAIEditor &waypoint, const char *path) {
    std::ofstream outstream(path);
    boost::archive::text_oarchive outarchive(outstream);
    outarchive << waypoint; 
}


#endif	/* WAYPOINTGRAPHSAVELOAD_H */

