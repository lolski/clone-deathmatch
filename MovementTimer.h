/* 
 * File:   MovementTimer.h
 * Author: lolski
 *
 * Created on September 2, 2009, 10:42 PM
 */

#ifndef MOVEMENTTIMER_H
#define	MOVEMENTTIMER_H

#include <irrlicht.h>

class MovementTimer {
public:
    MovementTimer();
    virtual ~MovementTimer();
    void init();
    void update();
    irr::f32 FACTOR;
    irr::f32 timeFactor;
    
private:
    irr::ITimer *timer;
    unsigned int currTime;
    unsigned int deltaTime;
};

#endif	/* MOVEMENTTIMER_H */

