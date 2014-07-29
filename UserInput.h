/* 
 * File:   UserInput.h
 * Author: lolski
 *
 * Created on April 13, 2011, 5:45 PM
 */

#ifndef USERINPUT_H
#define	USERINPUT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "GameManager.h"
#include "KeyCodeToStringw.h"
#include "ILevelDebugCallback.h"
    
class UserInput : public irr::IEventReceiver {
public:
    UserInput() {
        mouseMap[2];
        mouseMap[LMB] = false;
        mouseMap[RMB] = false;
        gamePaused = false;
        debugCallback = NULL;
        timer = GM::dev->getTimer();
    }
    void setDebugCallback(ILevelDebugCallback *debugCallback) {
        this->debugCallback = debugCallback;
        onKeyRightDePressed = &ILevelDebugCallback::onKeyRightDePressed;
        onKeyAppsDePressed = &ILevelDebugCallback::onKeyAppsDePressed;
        onKeyLWinDePressed = &ILevelDebugCallback::onKeyLWinDePressed;
        onKeySnapshotDePressed = &ILevelDebugCallback::onKeySnapshotDePressed;
        onKeyPeriodDePressed = &ILevelDebugCallback::onKeyPeriodDePressed;
        onKeyApostropheDePressed = &ILevelDebugCallback::onKeyApostropheDePressed;
        onKeySemiColonDePressed = &ILevelDebugCallback::onKeySemiColonDePressed;
        onKeyHelpDePressed = &ILevelDebugCallback::onKeyHelpDePressed;
        onKeyAlphabetMDePressed = &ILevelDebugCallback::onKeyAlphabetMDePressed;
        onKeyF1DePressed = &ILevelDebugCallback::onKeyF1DePressed;
        onKeyF2DePressed = &ILevelDebugCallback::onKeyF2DePressed;
        onKeyF3DePressed = &ILevelDebugCallback::onKeyF3DePressed;
        onKeyShiftF1DePressed = &ILevelDebugCallback::onKeyShiftF1DePressed;
        onKeyShiftF2DePressed = &ILevelDebugCallback::onKeyShiftF2DePressed;
        onKeyShiftF3DePressed = &ILevelDebugCallback::onKeyShiftF3DePressed;
        onKeyUpArrowDePressed = &ILevelDebugCallback::onKeyUpArrowDePressed;
        onKeyDownArrowDePressed = &ILevelDebugCallback::onKeyDownArrowDePressed;
        onKeyLeftArrowDePressed = &ILevelDebugCallback::onKeyLeftArrowDePressed;
        onKeyRightArrowDePressed = &ILevelDebugCallback::onKeyRightArrowDePressed;
    }
    virtual bool OnEvent(const irr::SEvent &event) {
        if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
            handleMiscKeyEvent(event);
            handleBotKeyEvent(event);
            handleDebugKeyEvent(event);
            handleSaveLoadWaypointKeyEvent(event);
        }
        if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
            handleMouseEvent(event);
        }
        return false;
    }
    bool mouseMap[];
    bool keyMap[irr::KEY_KEY_CODES_COUNT];
    bool gamePaused; // this should be on Level class
    irr::ITimer *timer;
    enum MOUSE_KEY {
        LMB = 0, RMB = 1
    };
private:
    ILevelDebugCallback *debugCallback;
    void (ILevelDebugCallback::*onKeyRightDePressed)();
    void (ILevelDebugCallback::*onKeyAppsDePressed)();
    void (ILevelDebugCallback::*onKeyLWinDePressed)();
    void (ILevelDebugCallback::*onKeySnapshotDePressed)();
    void (ILevelDebugCallback::*onKeyPeriodDePressed)();
    void (ILevelDebugCallback::*onKeyApostropheDePressed)();
    void (ILevelDebugCallback::*onKeySemiColonDePressed)();
    void (ILevelDebugCallback::*onKeyHelpDePressed)();
    void (ILevelDebugCallback::*onKeyAlphabetMDePressed)();
    void (ILevelDebugCallback::*onKeyF1DePressed)();
    void (ILevelDebugCallback::*onKeyF2DePressed)();
    void (ILevelDebugCallback::*onKeyF3DePressed)();
    void (ILevelDebugCallback::*onKeyShiftF1DePressed)();
    void (ILevelDebugCallback::*onKeyShiftF2DePressed)();
    void (ILevelDebugCallback::*onKeyShiftF3DePressed)();
    void (ILevelDebugCallback::*onKeyUpArrowDePressed)();
    void (ILevelDebugCallback::*onKeyDownArrowDePressed)();
    void (ILevelDebugCallback::*onKeyLeftArrowDePressed)();
    void (ILevelDebugCallback::*onKeyRightArrowDePressed)();
        
    void handleMouseEvent(const irr::SEvent &event) {
        if (event.MouseInput.Event == irr::EMIE_LMOUSE_LEFT_UP) {
            mouseMap[0] = false;
        }
        if (event.MouseInput.Event == irr::EMIE_LMOUSE_PRESSED_DOWN) {
            mouseMap[0] = true;
        }
        if (event.MouseInput.Event == irr::EMIE_RMOUSE_LEFT_UP) {
            mouseMap[RMB] = false;
        }
        if (event.MouseInput.Event == irr::EMIE_RMOUSE_PRESSED_DOWN) {
            mouseMap[RMB] = true;
        }
    }
    void handleBotKeyEvent(const irr::SEvent &event) {
        if (event.KeyInput.Key == irr::KEY_KEY_J && event.KeyInput.PressedDown) {
        }
        if (event.KeyInput.Key == irr::KEY_KEY_C && event.KeyInput.PressedDown) {
        }
        else if (event.KeyInput.Key == irr::KEY_KEY_C && !event.KeyInput.PressedDown) {
        }        
    }
    void handleMiscKeyEvent(const irr::SEvent &event) {
        switch (event.KeyInput.Key) {
         case irr::KEY_ESCAPE:
             // go to menu
             // toggle behavior
             if (!event.KeyInput.PressedDown) {
                 if (!gamePaused) {
                     gamePaused = true;
                 }
                 else {
                     gamePaused = false;

                 }
             }
             break;
                
        }
    }
    void handleDebugKeyEvent(const irr::SEvent &event) {
        switch (event.KeyInput.Key) {
            case irr::KEY_UP:
                if (!event.KeyInput.PressedDown) {
                    (debugCallback->*onKeyUpArrowDePressed)();
                }
                break;
            case irr::KEY_DOWN:
                if (!event.KeyInput.PressedDown) {
                    (debugCallback->*onKeyDownArrowDePressed)();
                }
                break;
            case irr::KEY_LEFT:
                if (!event.KeyInput.PressedDown) {
                    (debugCallback->*onKeyLeftArrowDePressed)();
                }
                break;
            case irr::KEY_RIGHT:
                // toggle behavior
                if (!event.KeyInput.PressedDown) {
                    //(debugCallback->*onKeyRightDePressed)();
                    (debugCallback->*onKeyRightArrowDePressed)();
                }
                break;
            case irr::KEY_APPS:
                // button behavior
                if (!event.KeyInput.PressedDown) {
                    (debugCallback->*onKeyAppsDePressed)();
                }
                break;
            case irr::KEY_LWIN:
                // button behavior
                if (!event.KeyInput.PressedDown) {
                    (debugCallback->*onKeyLWinDePressed)();
                }
                break;
            case irr::KEY_SNAPSHOT:
                // button behavior
                if (!event.KeyInput.PressedDown) {
                    (debugCallback->*onKeySnapshotDePressed)();
                }
                break;
            case irr::KEY_PERIOD:
                // button behavior
                if (!event.KeyInput.PressedDown) {
                    (debugCallback->*onKeyPeriodDePressed)();
                }
                break;
            case irr::KEY_HELP:
                // button behavior
                if (!keyMap[irr::KEY_HELP]) { //TODO: WHY?
                    (debugCallback->*onKeyHelpDePressed)();
                }
                break;
            case irr::KEY_KEY_M:
                if (!event.KeyInput.PressedDown) {
                    (debugCallback->*onKeyAlphabetMDePressed)();
                }
        }
    }
    
    void handleSaveLoadWaypointKeyEvent(const irr::SEvent &event) {
        // files are in waypoints/1.wpt, waypoints/2.wpt, waypoints/3.wpt
        // save: CTRL-F1, CTRL-F2, CTRL-F3
        // load: F1, F2, F3
        if (event.KeyInput.Shift) {
            if (event.KeyInput.Key == irr::KEY_F1) {
                if (!event.KeyInput.PressedDown) {
                    cout<<"saving to 1.wpt"<<endl;
                    (debugCallback->*onKeyShiftF1DePressed)();
                }
            }
            else if (event.KeyInput.Key == irr::KEY_F2) {
                if (!event.KeyInput.PressedDown) {
                    cout<<"saving to 2.wpt"<<endl;
                    (debugCallback->*onKeyShiftF2DePressed)();
                }
            }
            else if (event.KeyInput.Key == irr::KEY_F3) {
                if (!event.KeyInput.PressedDown) {
                    cout<<"saving to 3.wpt"<<endl;
                    (debugCallback->*onKeyShiftF3DePressed)();
                }
            }
        }
        else {
            if (event.KeyInput.Key == irr::KEY_F1) {
                if (!event.KeyInput.PressedDown) {
                    cout<<"loading from 1.wpt"<<endl;
                    (debugCallback->*onKeyF1DePressed)();
                }
            }
            else if (event.KeyInput.Key == irr::KEY_F2) {
                if (!event.KeyInput.PressedDown) {
                    cout<<"loading from 2.wpt"<<endl;
                    (debugCallback->*onKeyF2DePressed)();
                }
            }
            else if (event.KeyInput.Key == irr::KEY_F3) {
                if (!event.KeyInput.PressedDown) {
                    cout<<"loading from 3.wpt"<<endl;
                    (debugCallback->*onKeyF3DePressed)();
                }
            }
        }
    }
};

#ifdef	__cplusplus
}
#endif

#endif	/* USERINPUT_H */

