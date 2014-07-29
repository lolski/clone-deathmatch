/* 
 * File:   StateManager.h
 * Author: lolski
 *
 * Created on April 14, 2011, 12:21 AM
 */

#ifndef STATEMANAGER_H
#define	STATEMANAGER_H

class State;

class StateManager {
public:
    StateManager();
    void init();
    void cleanup();
    void update();
    void changeState(State *level);
private:
    State *current;
};

#endif	/* STATEMANAGER_H */