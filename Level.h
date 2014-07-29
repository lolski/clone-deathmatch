/* 
 * File:   Level.h
 * Author: lolski
 *
 * Created on April 14, 2011, 12:19 AM
 */

#ifndef LEVEL_H
#define	LEVEL_H

#include "config.h"
#include "IReturnFromInGameMenuCallback.h"
#include "State.h"
#include "BotManager.h"
#include "InGameMenu.h"
#include "Bot.h"
#include "Human.h"
#include "UserInput.h"
#include <stddef.h>
#include "SpawnPointCollection.h"
#include "SpawnPointDebug.h"
#include "LevelAIEditor.h"
#include "WaypointNodeType.h"
#include "LevelAIDebugVisual.h"
#include "WaypointGraphSaveLoad.h"
#include "GenerateUnsignedInt.h"
#include "debug.h"
#include "ID.h"
#include "HumanGUI.h"

class Level : public State, IReturnFromInGameMenuCallback, ILevelDebugCallback {
public:
    Level() {
        isExit = false;
        periodPressed = false;
    }

    virtual void init() {
        using namespace irr;
        // init
        GM::dev->setEventReceiver(&input);
        GM::dev->getCursorControl()->setVisible(false);
        GM::fsAccess->addZipFileArchive(MAP_ARCHIVE);

        ingame.init();
        ingame.setReturnFromInGameMenuCallback(this);
        
        input.setDebugCallback(this);

        // load waypoint data & set visualization
        loadWaypointGraph(levelAIEditor, WAYPOINT1_PATH);
        levelAIEditor.updateWaypointCache();
        levelAIDebug.setWaypointGraph(&levelAIEditor);
        levelAIDebug.redrawWaypointIndicatorCube();

        ISceneNode *playerAndMapRootSceneNode = GM::smgr->addEmptySceneNode(NULL);
        playerAndMapRootSceneNode->setName("playerAndMapRootSceneNode");

        // collision data
        scene::IAnimatedMesh *mapMesh = GM::smgr->getMesh(MAP_NAME);
        scene::ISceneNode *map = NULL;
        map = GM::smgr->addOctTreeSceneNode(mapMesh->getMesh(0));
        map->setID(MAP_SCENENODE_ID);
        map->setName("mapSceneNode");
        map->setPosition(core::vector3df(MAP_COORD[0], MAP_COORD[1], MAP_COORD[2]));
        triangles = GM::smgr->createOctTreeTriangleSelector(mapMesh->getMesh(0), map, 128);
        map->setTriangleSelector(triangles);
        playerAndMapRootSceneNode->addChild(map);
        
        player.setWorldTriangleData(triangles);
        player.levelAi = &levelAIEditor;
        player.spawnPoints = &(levelAIEditor.spawnPoints);
        player.sceneNodeToBotMap = &sceneNodeToBotMap;
        player.init();
        humanGUIDisplay = new HumanGUI(&player);
        sceneNodeToPlayerMap.insert(std::pair<ISceneNode *, Human *>(player.boundingBox, &player));
        // select random spawnpoint
        botMgr = new BotManager(triangles, &levelAIEditor, &player);
        botMgr->sceneNodeToBotMap = &sceneNodeToBotMap;
        botMgr->sceneNodeToPlayerMap = &sceneNodeToPlayerMap;
        for (int i = 0; i < BOT_COUNT; ++i) {
            Bot *b = botMgr->createBot();
        }
        botMgr->finalize();
    }

    virtual void update() {
        while (GM::dev->run() && GM::dev && !isExit) {
            if (input.gamePaused) {
                showInGameMenu();
            }
            else {
                handlePlayerShootingAnimation();
                
                GM::timer.update();
                
                GM::vdri->beginScene(true, true);
                player.update();
                botMgr->update();
                levelAIDebug.drawLines();
                humanGUIDisplay->update();
                GM::smgr->drawAll();
                humanGUIDisplay->healthDisplayCurrent->draw();
                humanGUIDisplay->crosshair->draw();
                GM::vdri->endScene();
            }
        }
    }
    virtual void cleanup() {
        triangles->drop();
        ingame.cleanup();
    }
    
    /* 
     Key event handlers
    */
    virtual void onContinueGame() {
    }
    virtual void onExitGame() {
        isExit = true;
    }

    virtual void onKeyRightDePressed() {

        std::cout<<"right"<<std::endl;
    }

    virtual void onKeyAppsDePressed() {
        // KEY ]
        levelAIDebug.toggleDebugMode();
        botMgr->toggleDebugMode();
    }

    virtual void onKeyLWinDePressed() {
        // KEY [
        std::cout<<"lwin"<<std::endl;
        
    }

    virtual void onKeySnapshotDePressed() {
        // KEY 
        std::cout<<"snapshot"<<std::endl;
        if (!levelAIEditor.isInConnectingProcess()) {
            // delete 
            ISceneNode *which = getSceneNodeFromCrosshair();
            if (which) {
                s32 id = which->getID();
                std::cout<<"deleted vertex: "<<id<<std::endl;
                levelAIEditor.removeNode(id);
                levelAIDebug.removeNodeVisualization(id);
            }
        }
        else {
            std::cerr<<"ERROR: this operation is disabled during the process of connecting two existing nodes"<<std::endl;
        }
    }

    virtual void onKeyPeriodDePressed() {
        if (!levelAIEditor.isInConnectingProcess()) {
            vector3df spawnPos = player.getPosition();
            vector3df fxPos = spawnPos;
            fxPos.Y -= 50;
            periodPressed = input.keyMap[irr::KEY_PERIOD];
            int id = generateUnsignedInt();
            VertexId newNode = levelAIEditor.createNextNodeConnected(id, spawnPos);
            levelAIDebug.createNextNodeConnectedVisualization(id, newNode);
        }
        else {
            std::cerr<<"ERROR: this operation is disabled during the process of connecting two existing nodes"<<std::endl;
        }
    }
    virtual void onKeySemiColonDePressed() {
        
        std::cout<<"semicolon"<<std::endl;
    }
    
    virtual void onKeyApostropheDePressed() {
        std::cout<<"appostrophe"<<std::endl;
    }
    virtual void onKeyHelpDePressed() {
        if (!levelAIEditor.isInConnectingProcess()) {
            // select a node 
            ISceneNode *which = getSceneNodeFromCrosshair();
            if (which) {
                s32 id = which->getID();
                levelAIEditor.selectNode(id);
                levelAIDebug.highlightNode(id);
            }
        }
        else {
            std::cerr<<"ERROR: this operation is disabled during the process of connecting two existing nodes"<<std::endl;
        }
    }
    virtual void onKeyAlphabetMDePressed() {
        // KEY M
        // select a node 
        if (!levelAIEditor.isInConnectingProcess()) {
            ISceneNode *sourceNode = getSceneNodeFromCrosshair();
            if (sourceNode) {
                s32 id = sourceNode->getID();
                levelAIEditor.selectNode(id);
                levelAIEditor.startConnectingProcess(id);
                levelAIDebug.highlightNode(id);
            }
        }
        else {          
            ISceneNode *destNode = getSceneNodeFromCrosshair();
            if (destNode == NULL) {
                // if the next selection is null or selects the same node
                levelAIEditor.cancelConnectingProcess();
                std::cout<<"WARNING: Cancelling node connection process"<<std::endl;
            }
            else {
                s32 id = destNode->getID();
                levelAIEditor.selectNode(id);
                levelAIEditor.finishConnectingProcess(id);
                levelAIDebug.highlightNode(id);
            }
        }
    }
    virtual void onKeyF1DePressed() {
        loadWaypointGraph(levelAIEditor, WAYPOINT1_PATH);
        levelAIDebug.redrawWaypointIndicatorCube();
    }
    virtual void onKeyF2DePressed() {
        loadWaypointGraph(levelAIEditor, WAYPOINT2_PATH);
        levelAIDebug.redrawWaypointIndicatorCube();
    }
    virtual void onKeyF3DePressed() {
        loadWaypointGraph(levelAIEditor, WAYPOINT3_PATH);
        levelAIDebug.redrawWaypointIndicatorCube();
    }
    virtual void onKeyShiftF1DePressed() {
        saveWaypointGraph(levelAIEditor, WAYPOINT1_PATH);
    }
    virtual void onKeyShiftF2DePressed() {
        saveWaypointGraph(levelAIEditor, WAYPOINT2_PATH);
    }
    virtual void onKeyShiftF3DePressed() {
        saveWaypointGraph(levelAIEditor, WAYPOINT3_PATH);
    }
    virtual void onKeyUpArrowDePressed() {
        // select node
        ISceneNode *which = getSceneNodeFromCrosshair();
        if (which) {
            s32 id = which->getID();
            VertexId whichWpNode;
            bool found = levelAIEditor.findNode(id, whichWpNode);
            if (found) {
                levelAIEditor.waypoint[whichWpNode].type = NORMAL;
                which->removeAll();
                which->setScale(vector3df(1, 1, 1));
            }
            else {
                std::cerr<<"error: no node selected"<<std::endl;
            }
        }
    }
    virtual void onKeyDownArrowDePressed() {
        // select node
        ISceneNode *which = getSceneNodeFromCrosshair();
        if (which) {
            s32 id = which->getID();
            VertexId whichWpNode;
            bool found = levelAIEditor.findNode(id, whichWpNode);
            if (found) {
                which->removeAll();
                which->setScale(vector3df(1, 1, 1));
                levelAIEditor.waypoint[whichWpNode].type = CAMP;
                vector3df orient = player.getRotation();
                orient.X *= -1; // invert orientation by Y axis
                orient.Z *= -1; // invert orientation by Y axis
                levelAIDebug.addCampPointFX(which, orient);
            }
            else {
                std::cerr<<"error: no node selected"<<std::endl;
            }
        }        
    }
    virtual void onKeyLeftArrowDePressed() {
        // select node
        ISceneNode *which = getSceneNodeFromCrosshair();
        if (which) {
            s32 id = which->getID();
            VertexId whichWpNode;
            bool found = levelAIEditor.findNode(id, whichWpNode);
            if (found) {
                vector3df position = levelAIEditor.waypoint[whichWpNode].position;
                position.Y -= 80;
                pVec3d(position);
                levelAIEditor.waypoint[whichWpNode].type = SPAWN_POINT;
                which->removeAll();
                which->setScale(vector3df(1, 1, 1));
                levelAIDebug.addSpawnPointFX(which);
            }
            else {
                std::cerr<<"error: no node selected"<<std::endl;
            }
        }
    }
    virtual void onKeyRightArrowDePressed() {
        // select node
        ISceneNode *which = getSceneNodeFromCrosshair();
        if (which) {
            s32 id = which->getID();
            VertexId whichWpNode;
            bool found = levelAIEditor.findNode(id, whichWpNode);
            if (found) {
                levelAIEditor.waypoint[whichWpNode].type = GOAL_ROAM;
                which->removeAll();
                which->setScale(vector3df(1, 4, 1));
            }
            else {
                std::cerr<<"error: no node selected"<<std::endl;
            }
        }
    }
    virtual ~Level() {
        delete botMgr;
        delete humanGUIDisplay;
    }
private:
    ISceneNode *getSceneNodeFromCrosshair() {
        irr::scene::ISceneCollisionManager *cm = GM::smgr->getSceneCollisionManager();
        line3df rayCollision = cm->getRayFromScreenCoordinates(vector2di(WIDTH/2, HEIGHT/2), player.getCameraSceneNode());
        ISceneNode *waypointDebugRootNode = GM::smgr->getSceneNodeFromName("waypointDebugRootNode");
        ISceneNode *which = cm->getSceneNodeFromRayBB(rayCollision, 0, false, waypointDebugRootNode);
        return which;
    }
    void showInGameMenu() {
        if (!ingame.isShown) {
            GM::dev->getTimer()->stop();
            player.getCameraSceneNode()->setInputReceiverEnabled(false);
            GM::dev->setEventReceiver(ingame.input);
            ingame.show();
            ingame.update();
            input.gamePaused = false;
            GM::dev->setEventReceiver(&input);
            player.getCameraSceneNode()->setInputReceiverEnabled(true);
            ingame.hide();
            GM::dev->getTimer()->start();
        }        
    }
    void handlePlayerShootingAnimation() {
        if (input.mouseMap[0]) {
            player.isShooting = true;
        } else {
            player.isShooting = false;
        }        
    }
    LevelAIEditor levelAIEditor;
    Human player;
    BotManager *botMgr;
    irr::scene::ITriangleSelector *triangles;
    UserInput input;
    InGameMenu ingame;
    SpawnPointCollection spawnPointCollection;
    SpawnPointDebug spawnPointDebug;
    LevelAIDebugVisual levelAIDebug;
    bool isExit;
    bool periodPressed;
    std::map<ISceneNode *, Bot *> sceneNodeToBotMap;
    std::map<ISceneNode *, Human *> sceneNodeToPlayerMap;
    HumanGUI *humanGUIDisplay;
};
#endif	/* LEVEL_H */

