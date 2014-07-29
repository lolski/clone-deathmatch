/* 
 * File:   IReturnFromInGameMenuCallback.h
 * Author: lolski
 *
 * Created on October 13, 2012, 1:33 AM
 */

#ifndef IRETURNFROMINGAMEMENUCALLBACK_H
#define	IRETURNFROMINGAMEMENUCALLBACK_H

class IReturnFromInGameMenuCallback {
public:
    virtual void onContinueGame() = 0;
    virtual void onExitGame() = 0;
};

#endif	/* IRETURNFROMINGAMEMENUCALLBACK_H */

