/* 
 * File:   BotMovement.h
 * Author: lolski
 *
 * Created on December 6, 2012, 8:25 PM
 */

#ifndef BOTMOVEMENT_H
#define	BOTMOVEMENT_H

#include <irrlicht.h>

using namespace irr;
using namespace irr::scene;

class BotMovement {
public:
    BotMovement(const ISceneNode *botRepr) {
        botRepresentation = botRepr;
    }
    void moveTo(const core::vector3df& pos) {
        botRepresentation->updateAbsolutePosition();
        core::vector3df oldPos = botRepresentation->getAbsolutePosition();

        if (oldPos.equals(pos, 0.001f))
                return;
        // update heading:
        core::vector3df dir = pos - oldPos;
        dir.Y = 0.0f;
        if (core::iszero(dir.getLengthSQ())) {
            return;
        }
        dir.normalize();

        core::vector3df heading(0.0f, 0.0f, 1.0f);

        core::quaternion q;
        q.rotationFromTo(heading, dir);

        core::vector3df eulerRadians;
        q.toEuler(eulerRadians);

        core::vector3df rot = eulerRadians * core::RADTODEG;
        botRepresentation->setRotation(rot);

        botRepresentation->setPosition(core::vector3df(pos.X, pos.Y+YOffset, pos.Z));
    }
private:
    ISceneNode *botRepresentation;
    float YOffset = 0;
};

#endif	/* BOTMOVEMENT_H */

