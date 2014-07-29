/* 
 * File:   Score.h
 * Author: lolski
 *
 * Created on October 24, 2012, 2:21 PM
 */

#ifndef SCORE_H
#define	SCORE_H

#include <irrlicht.h>

class Score {
public:
    void updateKill(player) {
        player.kill++
    }
    void updateFragged(player) {
        player.fragged++
    }
    void update() {
        if (isDisplayed) {
            
        }
    }
    bool isDisplayed;
    list of team1
    list of team2
private:
    
};

struct ScoreEntry {
public:
    stringw name;
    int kill;
    int fragged;
};
#endif	/* SCORE_H */

