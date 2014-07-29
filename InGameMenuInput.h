/* 
 * File:   InGameMenuInput.h
 * Author: lolski
 *
 * Created on September 27, 2011, 3:37 PM
 */

#ifndef INGAMEMENUINPUT_H
#define	INGAMEMENUINPUT_H

class InGameMenuInput : public irr::IEventReceiver {
public:
    InGameMenuInput(irr::core::rect<irr::s32> _continue, irr::core::rect<irr::s32> _exit) {
        continueGame = _continue;
        exit = _exit;
        continue_clicked = false;
        exit_clicked = false;
    }
    ~InGameMenuInput() {
        
    }
    virtual bool OnEvent(const irr::SEvent &event) {
        if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
            switch (event.MouseInput.Event) {
                case irr::EMIE_LMOUSE_LEFT_UP:
                    continue_clicked = continueGame.isPointInside(irr::core::vector2di(event.MouseInput.X, event.MouseInput.Y));
                    exit_clicked = exit.isPointInside(irr::core::vector2di(event.MouseInput.X, event.MouseInput.Y));
                    if (continue_clicked || exit_clicked) {
                        if (continue_clicked) {
                        }
                        if (exit_clicked) {
                        }
                    }
                    else {
                    }
                    break;
                case irr::EMIE_MOUSE_MOVED:
                    break;
            }
        }
        if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
            switch (event.KeyInput.Key) {
                case irr::KEY_ESCAPE:
                    // restart game
                    if (!event.KeyInput.PressedDown) {
                    }
                    break;
            }
        }
    }
    irr::core::rect<irr::s32> continueGame;
    irr::core::rect<irr::s32> exit;
    bool continue_clicked;
    bool exit_clicked;
};

#endif	/* INGAMEMENUINPUT_H */

