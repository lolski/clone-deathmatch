/* 
 * File:   BotManager.h
 * Author: lolski
 *
 * Created on April 20, 2011, 3:41 PM
 */

#ifndef BOTMANAGER_H
#define	BOTMANAGER_H

#include <vector>
#include "Bot.h"
#include "LevelAIEditor.h"
#include "Human.h"
#include <map>

class BotManager {
public:
    BotManager(irr::scene::ITriangleSelector *worldTriangleConstraint, LevelAIEditor *levelAi, Human *player);
    ~BotManager();
    Bot *createBot();
    Bot *removeBot(Bot *bot);
    void finalize();
    void update();
    void toggleDebugMode();
    Human *player;
    std::list<Bot *> enemies;
    irr::scene::ITriangleSelector *worldTriangleConstraint;
    LevelAIEditor *levelAi;
    std::map<ISceneNode *, Bot *> *sceneNodeToBotMap;
    std::map<ISceneNode *, Human *> *sceneNodeToPlayerMap;
    bool debugMode;
};

#endif	/* BOTMANAGER_H */

