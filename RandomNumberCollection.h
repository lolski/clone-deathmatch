/* 
 * File:   RandomNumberCollection.h
 * Author: lolski
 *
 * Created on October 22, 2012, 8:57 PM
 * contains two arrays of random numbers between a certain range
 */

#ifndef RANDOMNUMBERCOLLECTION_H
#define	RANDOMNUMBERCOLLECTION_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class RandomNumberCollection {
public:
    RandomNumberCollection() {
        srand(time(NULL));
        it = 1;
        for (int i = 0; i < 400; ++i) {
            int randpos = rand() % 1000;
            int rand_ = rand() % 2000 - 1000;
            randomPositive[i] = randpos / 50000.f;
            random[i] = rand_ / 5000.f;
        }
    }
    float getRandom(bool positiveNumber) {
        it = (it+3) % 400;
        float ret;
        if (positiveNumber) {
            ret = randomPositive[it];
        }
        else {
            ret = random[it];
        }
        return ret;
    }
private:
    int it;
    float randomPositive[400];
    float random[400];
};

#endif	/* RANDOMNUMBERCOLLECTION_H */

