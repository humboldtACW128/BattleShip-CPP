/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   battleship.h
 * Author: Austin
 *
 * Created on November 5, 2022, 5:25 PM
 */
#include <cstdlib>
#include <vector>
#include <tuple>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <stack>
#include <queue>


#include "ship.h"
#include "AVLTree.h"
#include "battleshipPlayer.h"
#include "Node.h"
#include "Graph.h"
#include "HashTable.h"

using namespace std;

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

class battleship {
public:
    battleship();
    battleship(const battleship& orig);
    virtual ~battleship();
    void startGame();
private:
    
    set<pair<int,int>> coords;
    battleshipPlayer p1;
    battleshipPlayer p2;
    
    set<pair<int,int>> createCoords();
    void setShipMap(list<pair<int,int>>&v,int,int,int);
    void printShipMap(list<pair<int,int>>&v,bool owner);
    void printCoords(set<pair<int,int>>&v);
    void printStat(map<char,int>& stats);
    void pushStat(char,map<char,int>&);
    bool checkSunk(ship& ship);
    bool checkLoss(ship* ships);
    bool checkFull(int cNum,list<pair<int,int>>& shipMap,int index, ship& s);
    void shootShip(set<pair<int,int>>& board,list<pair<int,int>>& shipMap, ship* ships, map<char,int>&,AVLTree&);
    void placeShip(ship& ship, set<pair<int,int>>& board,list<pair<int,int>>& shipMap);
    set<pair<int,int>>::iterator getCoord(set<pair<int,int>>& board,int x,int y);
    int createIndex(set<pair<int,int>>& board, set<pair<int,int>>::iterator);
    void bubbleSort(pair<int,int> arr[], int n);
    Node** trackpNames();
    int NumHash(string hashString);
    int char2int(char c);
    

};

#endif /* BATTLESHIP_H */

