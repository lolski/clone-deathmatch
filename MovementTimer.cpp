#include "MovementTimer.h"
#include <irrlicht.h>
#include "GameManager.h"

MovementTimer::MovementTimer() {
    timer = GM::dev->getTimer();
    FACTOR = 0.001f;
}

MovementTimer::~MovementTimer() {

}

void MovementTimer::init() {
    currTime = timer->getTime();
}

void MovementTimer::update() {
    deltaTime = timer->getTime() - currTime;
    currTime = currTime + deltaTime;
    timeFactor = deltaTime * FACTOR;
}