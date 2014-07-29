/* 
 * File:   BotPlayer.h
 * Author: lolski
 *
 * Created on October 26, 2012, 4:16 AM
 */

#ifndef BOTPLAYER_H
#define	BOTPLAYER_H

#include <irrlicht.h>

using namespace irr;
using namespace irr::core;
using namespace irr::scene;

class BotPlayer {
public:
    BotPlayer();
    void move(vector3df orient);
    void look(vector3df orient);
    void jump();
    void shoot();
    
private:
    float turnspeed;
    float accuracy;
    float bravery;
};

#endif	/* BOTPLAYER_H */

