/* 
 * File:   GameInit.h
 * Author: lolski
 *
 * Created on April 14, 2011, 12:41 AM
 */

#ifndef GAMEINIT_H
#define	GAMEINIT_H

#include "State.h"
#include "GameManager.h"

class GameInit : public State {
public:
    virtual void init() {
        //GM::dev->setEventReceiver(&GM::evtProcess);
        //GM::dev->getCursorControl()->setVisible(false);
        //GM::timer.init();
    }

    virtual void cleanup() {
    }

    virtual void update() {
    }
};

#endif	/* GAMEINIT_H */

