/* 
 * File:   CleanUp.h
 * Author: lolski
 *
 * Created on April 14, 2011, 1:18 PM
 */

#ifndef CLEANUP_H
#define	CLEANUP_H

#include "State.h"
#include "GameManager.h"

class CleanUp : public State {
public:
    CleanUp() {}
    void init() {}
    void update() {}
    void cleanup() {
        GM::dev->drop();
    }
};

#endif	/* CLEANUP_H */

