/* 
 * File:   MainMenuInput.h
 * Author: lolski
 *
 * Created on October 13, 2012, 12:04 AM
 */

#ifndef MAINMENUINPUT_H
#define	MAINMENUINPUT_H

#include <irrlicht.h>

class MainMenuInput : public irr::IEventReceiver {
public:
    MainMenuInput(irr::core::rect<irr::s32> _start, irr::core::rect<irr::s32> _exit) {
        start = _start;
        exit = _exit;
        start_clicked = false;
        exit_clicked = false;
    }
    virtual bool OnEvent(const irr::SEvent &event) {
        if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
            switch (event.MouseInput.Event) {
                case irr::EMIE_LMOUSE_LEFT_UP:
                    start_clicked = start.isPointInside(irr::core::vector2di(event.MouseInput.X, event.MouseInput.Y));
                    exit_clicked = exit.isPointInside(irr::core::vector2di(event.MouseInput.X, event.MouseInput.Y));
                    break;
                case irr::EMIE_MOUSE_MOVED:
                    break;
            }
        }
    }
    irr::core::rect<irr::s32> start;
    irr::core::rect<irr::s32> exit;
    bool start_clicked;
    bool exit_clicked;
};

#endif	/* MAINMENUINPUT_H */

