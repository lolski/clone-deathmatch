#include "BotManager.h"
#include "Bot.h"
#include "WaypointNodeType.h"
#include "ID.h"
#include <bitset>

BotManager::BotManager(irr::scene::ITriangleSelector *worldTriangleConstraint, LevelAIEditor *levelAi, Human *player) {
    this->worldTriangleConstraint = worldTriangleConstraint;
    this->levelAi = levelAi;
    this->player = player;
    debugMode = false;
}

BotManager::~BotManager() {
    
}

Bot *BotManager::createBot() {
    Bot *enemy = new Bot(worldTriangleConstraint, levelAi);
    enemy->init();
    enemies.push_back(enemy);
    enemy->spawnPointIndex = enemies.size();
    enemy->id = PLAYER_SCENENODE_ID << enemies.size();
    enemy->head->setID(enemy->id);
    enemy->spawnPoints = &(levelAi->spawnPoints);
    sceneNodeToBotMap->insert(std::pair<ISceneNode *, Bot *>(enemy->head, enemy));
    enemy->sceneNodeToBotMap = sceneNodeToBotMap;
    enemy->sceneNodeToPlayerMap = sceneNodeToPlayerMap;
    return enemy;
}

Bot *BotManager::removeBot(Bot *bot) {
    // search
    //delete bot;
    Bot *b = bot;
    enemies.remove(bot);
    delete b;
}
void BotManager::finalize() {
    for (std::list<Bot *>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        (*it)->testCollisionAgainst = (*it)->testCollisionAgainst | MAP_SCENENODE_ID | PLAYER_SCENENODE_ID;
        
        for (std::list<Bot *>::iterator jt = enemies.begin(); jt != enemies.end(); ++jt) {
            if (it != jt) {
                (*it)->testCollisionAgainst = (*it)->testCollisionAgainst | (*jt)->id;
            }
        }
        //(*it)->handleRespawnEvent();
    }
    
}
void BotManager::update() {
    for (std::list<Bot *>::iterator i = enemies.begin(); i != enemies.end(); ++i) {
        (*i)->update(player, &enemies);
    }
}
void BotManager::toggleDebugMode() {
    debugMode = !debugMode;
    for (std::list<Bot *>::iterator i = enemies.begin(); i != enemies.end(); ++i) {
        (*i)->toggleDebugMode();
    }
}