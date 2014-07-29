#include "StateManager.h"
#include "State.h"

StateManager::StateManager() {
}

void StateManager::init() {
    current->init();
}

void StateManager::cleanup() {
    current->cleanup();
}

void StateManager::update() {
    current->update();
}

void StateManager::changeState(State *level) {
    current = level;
}
