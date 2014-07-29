#include "State.h"
#include "StateManager.h"

State* State::changeState(StateManager* stateMgr, State* newState) {
    stateMgr->changeState(newState);
    return this;
}
