/* 
 * File:   NodeContainer.h
 * Author: lolski
 *
 * Created on December 7, 2012, 3:16 AM
 */

#ifndef NODECONTAINER_H
#define	NODECONTAINER_H

#include <irrlicht.h>
#include "WaypointNodeType.h"

using irr::core::vector3df;

struct WaypointNode {
public:
    WaypointNode() {}
    WaypointNode(vector3df pos, WaypointNodeType t = NORMAL): position(pos), type(t) {} 
    WaypointNodeType type;
    vector3df position;
};

#endif	/* NODECONTAINER_H */

