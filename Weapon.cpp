#include "debug.h"
#include "GameManager.h"
#include "Weapon.h"

Weapon::Weapon() {
    lastShot = 0;
    lastReload = 0;
    timer = GM::dev->getTimer();
    damage = 34;
    rateOfFire = 200;
    reloadTime = 3000;
    clipCapacity = 30;
    isReloading = false;
    //bullet  = GM::smgr->addCubeSceneNode(10);
}

irr::scene::ISceneNode *Weapon::shoot(irr::core::line3df ray) {
    irr::scene::ISceneNode *target = NULL;
    if (clipCapacity == 0) {
        reload();
    }
    if (!isReloading) {
        int currentShot = timer->getTime();
        if (currentShot - rateOfFire > lastShot) {
            //irr::scene::ISceneNodeAnimator *bulletAnim = GM::smgr->createFlyStraightAnimator(ray.start, ray.end, 7000);
            //GM::debug.setText(ray.start);
            //bullet->addAnimator(bulletAnim);
            target = GM::smgr->getSceneCollisionManager()->getSceneNodeFromRayBB(ray);

            //bulletAnim->drop();
            lastShot = currentShot;
            clipCapacity--;
        }
    }
    return target;
}

void Weapon::reload() {
    isReloading = true;
    int startReloading = timer->getTime();
    if (startReloading > lastReload + reloadTime) {
        isReloading = false;
        lastReload = startReloading + reloadTime;
        clipCapacity = 30;
    }
}

Weapon::~Weapon() {
    //delete timer;
}