/* 
 * File:   HumanGUI.h
 * Author: lolski
 *
 * Created on January 18, 2013, 5:25 PM
 */

#ifndef HUMANGUI_H
#define	HUMANGUI_H

#include "Human.h"
#include "GameManager.h"

using namespace irr;
using namespace irr::gui;
using namespace irr::core;

class HumanGUI {
public:
    HumanGUI(Human *h): CROSSHAIR_WIDTH(38), CROSSHAIR_HEIGHT(37) {
        human = h;
        
        crosshairPosition.X = WIDTH / 2 - CROSSHAIR_WIDTH / 2;
        crosshairPosition.Y = HEIGHT / 2 - CROSSHAIR_HEIGHT / 2;
        crosshair = GM::guiEnv->addImage(GM::vdri->getTexture(HUMAN_GUI_CROSSHAIR), crosshairPosition);
        
        currentHealth = h->health;
        healthDisplayPosition.X = 684;
        healthDisplayPosition.Y = 700;
        
        healthDisplay0 = GM::guiEnv->addImage(GM::vdri->getTexture(HUMAN_GUI_HEALTH_0), healthDisplayPosition);
        healthDisplay20 = GM::guiEnv->addImage(GM::vdri->getTexture(HUMAN_GUI_HEALTH_20), healthDisplayPosition);
        healthDisplay40 = GM::guiEnv->addImage(GM::vdri->getTexture(HUMAN_GUI_HEALTH_40), healthDisplayPosition);
        healthDisplay60 = GM::guiEnv->addImage(GM::vdri->getTexture(HUMAN_GUI_HEALTH_60), healthDisplayPosition);
        healthDisplay80 = GM::guiEnv->addImage(GM::vdri->getTexture(HUMAN_GUI_HEALTH_80), healthDisplayPosition);
        healthDisplay100 = GM::guiEnv->addImage(GM::vdri->getTexture(HUMAN_GUI_HEALTH_100), healthDisplayPosition);
        healthDisplayCurrent = healthDisplay0;
    }
    void update() {
        if (currentHealth != human->health) {
            currentHealth = human->health;
            switch (currentHealth) {
                case 0:
                    healthDisplayCurrent = healthDisplay0;
                    break;
                case 20:
                    healthDisplayCurrent = healthDisplay20;
                    break;
                case 40:
                    healthDisplayCurrent = healthDisplay40;
                    break;
                case 60:
                    healthDisplayCurrent = healthDisplay60;
                    break;
                case 80:
                    healthDisplayCurrent = healthDisplay80;
                    break;
                case 100:
                    healthDisplayCurrent = healthDisplay100;
                    break;
            }
        }
    }
    Human *human;
    int currentHealth;
    IGUIImage *healthDisplayCurrent, *healthDisplay0, *healthDisplay20, *healthDisplay40, *healthDisplay60, *healthDisplay80, *healthDisplay100;
    position2di healthDisplayPosition;
    
    IGUIImage *crosshair;
    position2di crosshairPosition;
    const int CROSSHAIR_WIDTH;
    const int CROSSHAIR_HEIGHT;
};

#endif	/* HUMANGUI_H */

