/*
 * File:   main.cpp
 * Author: lolski
 *
 * Created on August 13, 2009, 10:56 AM
 */

#include <irrlicht.h>
#include "GameManager.h"
#include "GameInit.h" 
#include "MainMenu.h"
#include "CleanUp.h"
#include "Level.h"

int main(int argc, char** argv) {
    using namespace irr;
    MainMenu menu;
    GM::stateMgr.changeState(&menu);
    GM::stateMgr.init();
    GM::stateMgr.update();
    bool start_clicked = menu.input->start_clicked;
    bool exit_clicked = menu.input->exit_clicked;
    GM::stateMgr.cleanup();
    
    if (start_clicked) {
        GameInit init;
        GM::stateMgr.changeState(&init);
        GM::stateMgr.init();
        GM::stateMgr.update();
        GM::stateMgr.cleanup();
    
        Level level;
        GM::stateMgr.changeState(&level);
        GM::stateMgr.init();
        GM::stateMgr.update();
        GM::stateMgr.cleanup();
    }
    
    CleanUp cleanUp;
    GM::stateMgr.changeState(&cleanUp);
    GM::stateMgr.init();
    GM::stateMgr.update();
    GM::stateMgr.cleanup();
    
    return 0;
}