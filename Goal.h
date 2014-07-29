/* 
 * File:   Goal.h
 * Author: lolski
 *
 * Created on December 6, 2012, 10:46 PM
 */

#ifndef GOAL_H
#define	GOAL_H

#include <irrlicht.h>

struct Goal {
    Goal() {
        
    }
    Goal(int action, const irr::core::vector3df &location) {
        this->action = action;
        this->location = location;
    }
    void setNewGoal(int action, irr::f32 locX, irr::f32 locY, irr::f32 locZ) {
        this->action = action;
        location.X = locX;
        location.Y = locY;
        location.Z = locZ;
    }
    static const int ROAM = 0, FIGHT = 1, FLEE = 2;
    int action;
    irr::core::vector3df location;
};

#endif	/* GOAL_H */

