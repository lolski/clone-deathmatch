/* 
 * File:   Weapon.h
 * Author: lolski
 *
 * Created on December 7, 2012, 6:29 PM
 */

#ifndef WEAPON_H
#define	WEAPON_H

#include <irrlicht.h>

class Weapon {
public:
    Weapon();
    virtual ~Weapon();
    irr::scene::ISceneNode *shoot(irr::core::line3df ray);
    void reload();
    irr::scene::ISceneNode *bullet;
public:
    irr::ITimer *timer;
    int damage;
    int rateOfFire;
    int reloadTime;
    int clipCapacity;
    int lastShot;
    int lastReload;
    bool isReloading;
    int accuracyFactor;
};


#endif	/* WEAPON_H */

