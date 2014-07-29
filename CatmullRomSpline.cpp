#include "CatmullRomSpline.h"

CatmullRomSpline::CatmullRomSpline() : P0(0.0f), P1(0.0f), P2(0.0f), P3(0.0f), speed(0.0f), time(FLT_MAX) {

}

CatmullRomSpline::CatmullRomSpline(const vector3df& p0, const vector3df& p1, const vector3df& p2, const vector3df& p3, irr::f32 s) : P0(p0), P1(p1), P2(p2), P3(p3), speed(s) {
    if (speed <= 0.0f) {
        time = FLT_MAX;
        return;
    }

    irr::f32 dt = 0.1f;
    time = getCatmullRomDist(dt) / speed;
}

CatmullRomSpline::~CatmullRomSpline() {
}

vector3df CatmullRomSpline::getCatmullRomPos
(const vector3df& p0, const vector3df& p1, const vector3df& p2, const vector3df& p3, irr::f32 t) {
    return 0.5f *
    (
        (2 * p1)
        + (-1.0f * p0 + p2) * t
        + (2.0f * p0 - 5.0f * p1 + 4.0f * p2 - p3) * powf(t, 2.0f)
    + (-1.0f * p0 + 3.0f * p1 - 3.0f * p2 + p3) * powf(t, 3.0f)
    );
}

void CatmullRomSpline::init(const vector3df& p0, const vector3df& p1, const vector3df& p2, const vector3df& p3, irr::f32 s) {
    P0 = p0;
    P1 = p1;
    P2 = p2;
    P3 = p3;

    speed = speed;
    if (speed <= 0.0f) {
        time = FLT_MAX;
    }
    else {
        irr::f32 dt = 0.1f;
        time = getCatmullRomDist(dt) / speed;
    }
}

bool CatmullRomSpline::calculatePosition(irr::f32 elapsedTime, vector3df& pos) {
    if (elapsedTime < 0.0f)
        return false; // bail out

    if (elapsedTime <= time) {
        irr::f32 t = elapsedTime / time;
        pos = getCatmullRomPos(P0, P1, P2, P3, t);
        return true; // re-run on next cycle
    }
    else {
        return false; // bail out
    }
}

irr::f32 CatmullRomSpline::getCatmullRomDist(irr::f32 dt) {
    int nums = int(1.0f / dt);
    if (nums <= 1)
        return -1.0f;

    irr::f32 dist = 0.0f;
    vector3df v1, v2;
    for (int n = 1; n < nums; ++n) {
        v1 = getCatmullRomPos(P0, P1, P2, P3, (n - 1) * dt);
        v2 = getCatmullRomPos(P0, P1, P2, P3, n * dt);
        dist += v1.getDistanceFrom(v2);
    }

    return dist;

}

irr::f32 CatmullRomSpline::getTotalDistance(const std::vector<vector3df>& points) {
    int nums = int(points.size());
    if (nums < 2) {
        return -1.0;
    }
    
    irr::f32 dist = 0.0f;
    vector3df v1, v2;
    for (int n = 1; n < nums; ++n) {
        v1 = points.at(n - 1);
        v2 = points.at(n);

        dist += v1.getDistanceFrom(v2);
    }
    return dist;
}
