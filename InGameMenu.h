/* 
 * File:   IngameMenu.h
 * Author: lolski
 *
 * Created on August 28, 2011, 4:06 PM
 */

#ifndef INGAMEMENU_H
#define	INGAMEMENU_H

#include <irrlicht.h>
#include "State.h"
#include "InGameMenuInput.h"
#include "IReturnFromInGameMenuCallback.h"
#include "config.h"

class InGameMenu {
public:
    InGameMenu(): input(NULL), continuegame(NULL), exitgame(NULL), onContinueGame(NULL), onExitGame(NULL), returnFromInGameMenuCallback(NULL) {
        isShown = false;
    }
    void init() {
        irr::s32 x = (WIDTH - MENU_OPTION_WIDTH) / 2;
        irr::s32 y = (HEIGHT - MENU_OPTION_HEIGHT) / 2;
        irr::core::position2di topcenter(x, y - 30 + 150);
        irr::core::position2di botcenter(x + 4, y + 30 + 150);
        bg = GM::guiEnv->addImage(GM::vdri->getTexture(MENU_BG), irr::core::position2di(0, 0));
        continuegame = GM::guiEnv->addImage(GM::vdri->getTexture(MENU_CONTINUE), topcenter);
        exitgame = GM::guiEnv->addImage(GM::vdri->getTexture(MENU_EXIT), botcenter);
        input = new InGameMenuInput(continuegame->getAbsoluteClippingRect(), exitgame->getAbsoluteClippingRect());

    }
    void setReturnFromInGameMenuCallback(IReturnFromInGameMenuCallback *ref) {
        returnFromInGameMenuCallback = ref;
        onContinueGame = &IReturnFromInGameMenuCallback::onContinueGame;
        onExitGame = &IReturnFromInGameMenuCallback::onExitGame;
    }
    void cleanup() {
        bg->remove();
        continuegame->remove();
        exitgame->remove();
        delete input;
        input = NULL;
    }
    void update() {   
        while (GM::dev->run() && GM::dev) {
            GM::vdri->beginScene(true, true, irr::video::SColor(0, 200, 200, 200));
            GM::guiEnv->drawAll();
            GM::vdri->endScene();
            if (input->exit_clicked || input->continue_clicked) {
                if (input->exit_clicked) {
                    (returnFromInGameMenuCallback->*onExitGame)();
                    input->exit_clicked = false;
                }
                if (input->continue_clicked) {
                    (returnFromInGameMenuCallback->*onContinueGame)();
                    input->continue_clicked = false;
                }
                break;
            }
        }
        // now isExitClicked == true
    }
    void show() {
        isShown = true;
        GM::dev->getCursorControl()->setVisible(true);
        continuegame->setVisible(true);
        exitgame->setVisible(true);
    }
    void hide() {
        isShown = false;
        GM::dev->getCursorControl()->setVisible(false);
        continuegame->setVisible(false);
        exitgame->setVisible(false);
        
    }
    
    void (IReturnFromInGameMenuCallback::*onContinueGame)();
    void (IReturnFromInGameMenuCallback::*onExitGame)();
    
    bool isShown;
    InGameMenuInput *input;
    IReturnFromInGameMenuCallback *returnFromInGameMenuCallback;
    irr::gui::IGUIImage *bg;
    irr::gui::IGUIImage *continuegame;
    irr::gui::IGUIImage *exitgame;
private:
};


#endif	/* INGAMEMENU_H */

