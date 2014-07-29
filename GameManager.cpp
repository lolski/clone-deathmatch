#include "GameManager.h"
#include <irrlicht.h>
#include "config.h"

irr::IrrlichtDevice *GM::dev = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(WIDTH, HEIGHT), 16, false, true, false, NULL);
irr::video::IVideoDriver *GM::vdri = GM::dev->getVideoDriver();
irr::gui::IGUIEnvironment *GM::guiEnv = GM::dev->getGUIEnvironment();
irr::scene::ISceneManager *GM::smgr = GM::dev->getSceneManager();
irr::io::IFileSystem *GM::fsAccess = GM::dev->getFileSystem();
Debug GM::debug(GM::guiEnv);
StateManager GM::stateMgr;
//UserInput GM::evtProcess;
MovementTimer GM::timer;