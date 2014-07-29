/* 
 * File:   GameManager.h
 * Author: lolski
 *
 * Created on April 14, 2011, 12:12 AM
 */

#ifndef GAMEMANAGER_H
#define	GAMEMANAGER_H

#include <irrlicht.h>
#include "StateManager.h"
//#include "UserInput.h"
#include "MovementTimer.h"
#include "debug.h"

class GM {
public:
    GM();
    static int whoah;
    static irr::IrrlichtDevice *dev;
    static irr::video::IVideoDriver *vdri;
    static irr::gui::IGUIEnvironment *guiEnv;
    static irr::scene::ISceneManager *smgr;
    static irr::io::IFileSystem *fsAccess;

    static MovementTimer timer;
    static Debug debug;
    static StateManager stateMgr;
    //static UserInput evtProcess;
};

#endif	/* GAMEMANAGER_H */

