/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   battleshipPlayer.cpp
 * Author: Austin
 * 
 * Created on November 6, 2022, 8:24 AM
 */

#include "battleshipPlayer.h"

battleshipPlayer::battleshipPlayer() {
    pMap = createShipMap();
    stat = createStatTrack();
    ships = createShips();
}

battleshipPlayer::battleshipPlayer(const battleshipPlayer& orig) {
}

battleshipPlayer::~battleshipPlayer() {
}

map<char,int> battleshipPlayer::createStatTrack() {
    
    map<char,int> stats;
    stats.insert({'M',0});
    stats.insert({'X',0});
    return stats;
}

list<pair<int,int>> battleshipPlayer::createShipMap() {
    
    list<pair<int,int>> temp;
    for(int i =1;i <= 10;i++) {
        for(int j =1;j <= 10;j++) {
            pair<int,int> test;
            temp.push_back(test);
        }
    }
    fill(temp.begin(),temp.end(),make_pair(0,0));
    return temp;
}

ship* battleshipPlayer::createShips() {
    
    ship * ships = new ship[5];
    int size = 2;
    for(int i = 0;i < 4;i++) {
        ships[i].number = i + 1;
        ships[i].size = size;
        ships[i].pegs = new bool[size];
        for(int j = 0;j < ships[i].size;j++) {
            ships[i].pegs[j] = false;
        }
        ships[i].sunk = false;
        size++;
        //cout << ships[i].number << " " << ships[i].size << " " << ships[i].sunk << endl;// @Debug
    }
    ships[4].number = 5;
    ships[4].size = 3;
    ships[4].pegs = new bool[ships[4].size];
    for(int i = 0;i < ships[4].size;i++) {
        ships[4].pegs[i] = false;
    }
    ships[4].sunk = false;
    return ships;
}