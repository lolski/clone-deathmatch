/* 
 * File:   CatmullRomSpline.h
 * Author: lolski
 *
 * Created on December 7, 2012, 12:06 AM
 */

#ifndef CATMULLROMSPLINE_H
#define	CATMULLROMSPLINE_H

#include <vector>
#include <irrlicht.h>

using irr::core::vector3df;

class CatmullRomSpline {
public:
    CatmullRomSpline();
    CatmullRomSpline(const vector3df& p0, const vector3df& p1, const vector3df& p2, const vector3df& p3, irr::f32 speed);
    ~CatmullRomSpline();

    static vector3df getCatmullRomPos(const vector3df& p0,const vector3df& p1, const vector3df& p2, const vector3df& p3, irr::f32 t);
    void init(const vector3df& p0, const vector3df& p1, const vector3df& p2, const vector3df& p3, irr::f32 speed);
    bool calculatePosition(irr::f32 elapsedTime, vector3df& pos);
    irr::f32 getEstimatedTime();
    irr::f32 getCatmullRomDist(irr::f32 dt);
    static irr::f32 getTotalDistance(const std::vector<vector3df> &points);

    irr::f32 getSpeed() const { return speed; }
    irr::f32 getTotalTime() const { return time; }

private:
    vector3df P0;
    vector3df P1;
    vector3df P2;
    vector3df P3;

    irr::f32 speed;
    irr::f32 time;
};

#endif	/* CATMULLROMSPLINE_H */

