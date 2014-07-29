/* 
 * File:   State.h
 * Author: lolski
 *
 * Created on April 14, 2011, 12:35 AM
 */

#ifndef STATE_H
#define	STATE_H

class StateManager;

class State {
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void cleanup() = 0;
    State *changeState(StateManager *stateMgr, State *newState);
};

#endif	/* STATE_H */

