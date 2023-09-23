/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   battleshipPlayer.h
 * Author: Austin
 *
 * Created on November 6, 2022, 8:24 AM
 */

#include <list>
#include <map>
#include <set>


#include "ship.h"

using namespace std;

#ifndef BATTLESHIPPLAYER_H
#define BATTLESHIPPLAYER_H

class battleshipPlayer {
public:
    battleshipPlayer();
    battleshipPlayer(const battleshipPlayer& orig);
    virtual ~battleshipPlayer();
    list<pair<int,int>>& getMap(){return pMap;};
    map<char,int>& getStat(){return stat;};
    ship* getShips(){return ships;};
    list<pair<int,int>> createShipMap();
    ship* createShips();
    map<char,int> createStatTrack();
private:   
    list<pair<int,int>> pMap;
    map<char,int> stat;
    ship* ships;
};

#endif /* BATTLESHIPPLAYER_H */

