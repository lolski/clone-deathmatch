/* 
 * File:   ILevelDebugCallback.h
 * Author: lolski
 *
 * Created on October 23, 2012, 6:29 PM
 */

#ifndef ILEVELDEBUGCALLBACK_H
#define	ILEVELDEBUGCALLBACK_H

class ILevelDebugCallback {
public:
    virtual void onKeyRightDePressed() = 0;
    virtual void onKeyAppsDePressed() = 0;
    virtual void onKeyLWinDePressed() = 0;
    virtual void onKeySnapshotDePressed() = 0;
    virtual void onKeyPeriodDePressed() = 0;
    virtual void onKeyApostropheDePressed() = 0;
    virtual void onKeySemiColonDePressed() = 0;
    virtual void onKeyHelpDePressed() = 0;
    virtual void onKeyAlphabetMDePressed() = 0;
    virtual void onKeyF1DePressed() = 0;
    virtual void onKeyF2DePressed() = 0;
    virtual void onKeyF3DePressed() = 0;
    virtual void onKeyShiftF1DePressed() = 0;
    virtual void onKeyShiftF2DePressed() = 0;
    virtual void onKeyShiftF3DePressed() = 0;
    virtual void onKeyUpArrowDePressed() = 0;
    virtual void onKeyDownArrowDePressed() = 0;
    virtual void onKeyLeftArrowDePressed() = 0;
    virtual void onKeyRightArrowDePressed() = 0;
};

#endif	/* ILEVELDEBUGCALLBACK_H */

