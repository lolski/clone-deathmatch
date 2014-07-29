/* 
 * File:   MainMenu.h
 * Author: lolski
 *
 * Created on August 27, 2011, 12:49 AM
 */

#ifndef MAINMENU_H
#define	MAINMENU_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "config.h"
#include "State.h"
#include "GameManager.h"
#include "MainMenuInput.h"

class MainMenu : public State {
public:

    MainMenu() : input(NULL), bg(NULL), startgame(NULL), exitgame(NULL) {
        isShown = false;
    }

    virtual void init() {
        // draw menu
        irr::s32 x = (WIDTH - MENU_OPTION_WIDTH) / 2;
        irr::s32 y = (HEIGHT - MENU_OPTION_HEIGHT) / 2;
        irr::core::position2di topcenter(x, y - 30 + 150);
        irr::core::position2di botcenter(x + 4, y + 30 + 150);
        bg = GM::guiEnv->addImage(GM::vdri->getTexture(MENU_BG), irr::core::position2di(0, 0));
        startgame = GM::guiEnv->addImage(GM::vdri->getTexture(MENU_START), topcenter);
        exitgame = GM::guiEnv->addImage(GM::vdri->getTexture(MENU_EXIT), botcenter);

        //startgame->setAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);

        // change user input mode to menu input
        GM::dev->getCursorControl()->setVisible(true);
        input = new MainMenuInput(startgame->getAbsoluteClippingRect(), exitgame->getAbsoluteClippingRect());
        GM::dev->setEventReceiver(input);

    }

    virtual void cleanup() {
        bg->remove();
        startgame->remove();
        exitgame->remove();
        delete input;
        input = NULL;
    }

    virtual void update() {
        // respond to key press
        while (GM::dev->run() && GM::dev) {
            GM::vdri->beginScene(true, true, irr::video::SColor(0, 200, 200, 200));
            GM::guiEnv->drawAll();
            GM::vdri->endScene();
            if (input->start_clicked || input->exit_clicked) {
                hide();
                break;
            }
        }
    }
    void show() {
        GM::dev->getCursorControl()->setVisible(true);
        startgame->setVisible(true);
        exitgame->setVisible(true);
    }
    void hide() {
        GM::dev->getCursorControl()->setVisible(false);
        startgame->setVisible(false);
        exitgame->setVisible(false);
    }
    MainMenuInput *input;
    irr::gui::IGUIImage *startgame;
    irr::gui::IGUIImage *exitgame;
    irr::gui::IGUIImage *bg;
    bool isShown;
};



#ifdef	__cplusplus
}
#endif

#endif	/* MAINMENU_H */

