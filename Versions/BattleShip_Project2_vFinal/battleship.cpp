/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   battleship.cpp
 * Author: Austin
 * 
 * Created on November 5, 2022, 5:25 PM
 */

#include "battleship.h"


using namespace std;

battleship::battleship() {   
    coords = createCoords();//Holds coords of the map.
}

battleship::battleship(const battleship& orig) {
}

battleship::~battleship() { 
}

int battleship::NumHash(string hashString) {
    
    int hash = 0;
    //hash = ((char2int(hashString[0]) + char2int(hashString[1]))*(char2int(hashString[0]) + char2int(hashString[1]) + 1)/2) + char2int(hashString[1]);
    for(int i = 0;i < hashString.length();i++) {
        if(i == 0) {
           hash += char2int(hashString[i]) * hashString[i] + hashString[i + 1];
        }
        else if(i == 1) {
           hash += char2int(hashString[i]) * hashString[i] + hashString[i - 1]; 
        }
        else {
            hash += char2int(hashString[i]);
        }
    }
    return hash;
}

int battleship::char2int(char c) {
    
    
    if(c == 'A' || c == 'B' || c == 'C') {
        return 2;
    }
    else if (c == 'D' || c == 'E' || c == 'F') {
        return 3;
    }
    else if (c == 'G' || c == 'H' || c == 'I') {
        return 4;
    }
    else if (c == 'J' || c == 'K' || c == 'L') {
        return 5;
    }
    else if (c == 'M' || c == 'N' || c == 'O') {
        return 6;
    }
    else if (c == 'P' || c == 'Q' || c == 'R' || c == 'S') {
        return 7;
    }
    else if (c == 'T' || c == 'U' || c == 'V') {
        return 8;
    }
    else {
        return 9;
    }
}

Node** battleship::trackpNames() {
    
    HashTable HT;
    Node **table = NULL;
    int size = 13;
    string *names = new string[2];

    cout << "Hello can we have each player enter there names now" << endl;
    names[0] = "Player One";
    names[1] = "Player Two";
    table = HT.insrtNode(names,2,size);
    for(int i = 0;i < 2;i++) {
        cout << "Player #" << i+1 << " enter you name now." << endl;
        cin >> names[i];
    }  
    table[HT.ClayHash("Player One")% size]->data = names[0];
    table[HT.ClayHash("Player Two")% size]->data = names[1];
    
//  outfile << endl;
//  outfile.close();
    return table;
};


// A function to implement bubble sort
void battleship::bubbleSort(pair<int,int> arr[], int n)
{
    // Base case
    if (n == 1)
        return;
 
    int count = 0;
    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            count++;
        }
 
      // Check if any recursion happens or not
      // If any recursion is not happen then return
      if (count==0)
           return;
 
    // Largest element is fixed,
    // recur for remaining array
    bubbleSort(arr, n-1);
}

void battleship::startGame() {
    bool gameOver = false;
    HashTable table;
    Node** players;
    cout << "Welcome to my battleship game. Hope you like it!" << endl;
    players = trackpNames();
    cout << "Lets Begin. Well have " << players[table.ClayHash("Player One") % 13]->data << " place there ships now." << endl << endl;
    printShipMap(p1.getMap(),true);
   for(int i =0;i < 5;i++) {
        cout << "Your ship has a length of :" << p1.getShips()[i].size << endl; 
        placeShip(p1.getShips()[i],coords,p1.getMap());
    }
    cout << "Great. Well have " << players[table.ClayHash("Player Two") % 13]->data << " place there ships now." << endl;
    printShipMap(p2.getMap(),true);
    for(int i =0;i < 5;i++) {
        cout << "Your ship has a length of :" << p2.getShips()[i].size << endl; 
        placeShip(p2.getShips()[i],coords,p2.getMap());
    }
    cout << "Now that the ship's have been place lets start getting to the action!!!" << endl;
    
    while(!gameOver) {
        
        cout << players[table.ClayHash("Player One") % 13]->data << " will now shoot there shot!" << endl;
        cout << "Here is your view of " << players[table.ClayHash("Player Two") % 13]->data << "'s map." << endl;
        printShipMap(p2.getMap(),false);
        shootShip(coords,p2.getMap(),p2.getShips(),p1.getStat(),p1.shots);
        printShipMap(p2.getMap(),false);
        if (checkLoss(p2.getShips())) {
            cout << players[table.ClayHash("Player One") % 13]->data << " wins by sinking the ships.";
            gameOver = true;
            break;
        }
        cout << players[table.ClayHash("Player Two") % 13]->data << " will now shoot there shot!" << endl;
        cout << "Here is your view of " << players[table.ClayHash("Player One") % 13]->data << "'s map." << endl;
        printShipMap(p1.getMap(),false);
        shootShip(coords,p1.getMap(),p1.getShips(),p2.getStat(),p2.shots);
        printShipMap(p1.getMap(),false);
        if (checkLoss(p1.getShips())) {
            cout << players[table.ClayHash("Player Two") % 13]->data << " wins by sinking the ships.";
            gameOver = true;
            break;
        }   
    }
    
    cout << endl << "Now lets see some stats." << endl;
    cout << players[table.ClayHash("Player One") % 13]->data<< endl;
    printStat(p1.getStat());
    cout  << players[table.ClayHash("Player Two") % 13]->data<< endl;
    printStat(p2.getStat());
    
    int choice = 0;
    while(choice < 1 || choice > 2) {
        cout  << endl << "Would you like to see the log off all positions that were shot. (1-Yes) (2-No)" << endl;
        cin >> choice;
        if(choice == 1 || choice == 2) {
            if(choice == 1) {
                AVLTree p1Shots = p1.shots;
                AVLTree p2Shots = p2.shots;
                p1Shots.balance(p1Shots.root);
                p2Shots.balance(p2Shots.root);
                
                cout << "Here is the view of " << players[table.ClayHash("Player One") % 13]->data <<"'s shot history." << endl;
                p1Shots.inorder(p1Shots.root);
                cout << endl;
                cout << "Here is the view of " << players[table.ClayHash("Player Two") % 13]->data <<"'s shot history." << endl;
                p2Shots.inorder(p2Shots.root);
                cout << endl;
            }
            else {
                cout << "Your loss." << endl;
            }
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }
    cout << "Hope you liked the game if you lost its time to get good." << endl;
}

void battleship::printStat(map<char,int>& stats) {   
    cout << endl << "You had a total of " << stats['M'] << " misses." << endl;
    cout << "You had a total of " << stats['X'] << " hits." << endl;
}
void battleship::pushStat(char stat,map<char,int>& stats) {   
    stats[stat]++;   
}

bool battleship::checkFull(int cNum,list<pair<int,int>>& shipMap,int index, ship& ship) {
    
    int full = false;
    switch(cNum) {
        case 1:
                    for(int i = 0;i < ship.size;i++) {
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index - i;j++) {
                            it++;
                        }
                        pair<int,int> temp = *it;
                        //pair<int,int> temp = shipMap[index - i];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                            break;
                        }
                    }
            break;
        case 2:
                    for(int i = 0;i < ship.size;i++) {
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index + i;j++) {
                            it++;
                        }
                        pair<int,int> temp = *it;
                        //pair<int,int> temp = shipMap[index + i];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                            break;
                        }
                    }
            break;
        case 3:
                    for(int i = 0;i < ship.size;i++) {
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index - (10*i);j++) {
                            it++;
                        }
                        pair<int,int> temp = *it;
                        //pair<int,int> temp = shipMap[index - (10*i)];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                            break;
                        }
                    }
            break;
        case 4:
                    for(int i = 0;i < ship.size;i++) {
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index + (10*i);j++) {
                            it++;
                        }
                        pair<int,int> temp = *it;
                        //pair<int,int> temp = shipMap[index + (10*i)];
                        if (temp.first != 0 ) {
                            full = true;
                            cout << "This place was filled" << endl;
                            break;
                        }
                    }
            break;
        default:
            cout << "Buggy";
            break;
  
    }
    return full;
}

void battleship::placeShip(ship& ship, set<pair<int,int>>& board,list<pair<int,int>>& shipMap) {
    
    int x,y,r;
    Graph g(11);
    
    for(int i = 1 ; i <= 10;i++) {
        for(int j = 1;j <= 10;j++) {
            g.addEdge(i,j);
        }
    }
    cout << endl <<"Where would you like to place your ship reference from point (1,1) of your ship" <<endl;
    cout << "Remember the board is a 10x10 (1,1)-(10,10)" <<endl;
    cout <<"Enter the row coordinate for your placement(top->bottom)" << endl;
    cin >> x;
    cout<< "Enter the column coordinate for your placement(left->right)" <<endl;
    cin >> y;
    cout << "Enter the rotation for your ship" << endl;
    cout << "1)Left , 2)Right , 3)Up , 4)Down" << endl;
    cin >> r;
    cin.clear();
    cin.ignore(100, '\n');
    if(g.findNode(x,y) && r >=1 && r <= 4) {
        switch(r) {
            case 1:
                if(y-ship.size >= 0) {
                    int index = createIndex(board,getCoord(board,x,y));
                     if (checkFull(r,shipMap,index,ship)) {
                         cout << "There was a ship in that position try a new spot." << endl << endl;
                         printShipMap(shipMap,true);
                         placeShip(ship,board,shipMap);
                         return;
                     };
                    
                    for(int i = 0;i < ship.size;i++) { 
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index - i;j++) {
                            it++;
                        }
                        *it = make_pair(ship.number,i+1);
                        //shipMap[index - i] = make_pair(ship.number,i+1);
                    } 
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
                    return;
                }
                break;
            case 2:
                if(y+ship.size <= 11) {
                    int index = createIndex(board,getCoord(board,x,y));
                     if (checkFull(r,shipMap,index,ship)) {
                         cout << "There was a ship in that position try a new spot." << endl << endl;
                         printShipMap(shipMap,true);
                         placeShip(ship,board,shipMap);
                         return;
                     };
                    for(int i = 0;i < ship.size;i++) {
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index + i;j++) {
                            it++;
                        }
                        *it = make_pair(ship.number,i+1);
                        //shipMap[index + i] = make_pair(ship.number,i+1);
                    } 
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
                    return;
                }
                break;
            case 3:
                if(x-ship.size >= 0) {

                    int index = createIndex(board,getCoord(board,x,y));
                    //shipMap[index] = make_pair(1,1); @Debug
                     if (checkFull(r,shipMap,index,ship)) {
                         cout << "There was a ship in that position try a new spot." << endl << endl;
                         printShipMap(shipMap,true);
                         placeShip(ship,board,shipMap);
                         return;
                     };
                    for(int i = 0;i < ship.size;i++) {
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index - (10*i);j++) {
                            it++;
                        }
                        *it = make_pair(ship.number,i+1);
                        //shipMap[index - (10*i)] = make_pair(ship.number,i+1);
                    }
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
                    return;
                }
                break;
            case 4:
                if(x+ship.size <= 11) {
                    int index = createIndex(board,getCoord(board,x,y));
                     if (checkFull(r,shipMap,index,ship)) {
                         cout << "There was a ship in that position try a new spot." << endl << endl;
                         printShipMap(shipMap,true);
                         placeShip(ship,board,shipMap);
                         return;
                     };
                    for(int i = 0;i < ship.size;i++) {
                        list<pair<int,int>>::iterator it = shipMap.begin();
                        for(int j =0;j < index + (10*i);j++) {
                            it++;
                        }
                        *it = make_pair(ship.number,i+1);
                        //shipMap[index + (10*i)] = make_pair(ship.number,i+1);
                    } 
                } else {
                    
                    cout << "You can't place a ship here its too long" << endl;
                    placeShip(ship,board,shipMap);
                    return;
                }
                break;
            default:
                cout << "Invalid coordinate was not caught by the check" << endl;
        }
        
    }
    else {
        cout << "Invalid coordinate" <<endl;
        placeShip(ship,board,shipMap);
        return;
    }
    printShipMap(shipMap,true);
}

int battleship::createIndex(set<pair<int,int>>& v, set<pair<int,int>>::iterator it) {
    return distance(v.begin(), it);
}

set<pair<int,int>>::iterator battleship::getCoord(set<pair<int,int>>& v,int x,int y) { 
    return find(v.begin(), v.end(), pair<int,int>(x,y));
}


void battleship::shootShip(set<pair<int,int>>& board,list<pair<int,int>>& shipMap, ship* ships, map<char,int>& stats, AVLTree& shots) {
    int r = 0,
        c = 0,
        index = 0;
    Graph g(11);
    
    for(int i = 1 ; i <= 10;i++) {
        for(int j = 1;j <= 10;j++) {
            g.addEdge(i,j);
        }
    }
    do {
        cout << "Where would you like to send you shot?" << endl;
        cout << "Enter the row coordinate now" <<endl;
        cin >> r;
        cout << "Enter the column coordinate now" <<endl;
        cin >> c;
        cin.clear();
        cin.ignore(100, '\n');
        if(r < 1 || r > 10 || c < 1 || c > 10) {
            cout << "Invalid coordinate" << " here"<< endl;
        }         
    }
    while(!g.findNode(r,c));
    index = createIndex(board,getCoord(board,r,c));
    //cout << index;
    list<pair<int,int>>::iterator it = shipMap.begin();
    for(int i =0;i < index;i++) {
        it++;
    }
    pair<int,int> temp = *it;
    //pair<int,int> temp = shipMap[index];
    if(temp.first == 0) {
        cout << "You missed try harder next time." << endl;
        setShipMap(shipMap,index,8,8);
        pushStat('M',stats);
    }
    else if(temp.first == 8 || temp.first == 9) {
        cout << "You have already shot here. How do you mess up that bad?" << endl;
    }
    else {
        cout << "You hit ship #" << temp.first << endl;
        pushStat('X',stats);
        //cout << ships[temp.first - 1].number << " " << temp.second; //@Debug
        ships[temp.first - 1].pegs[temp.second - 1] = true;
//        for(int i = 0;i< ships[temp.first - 1].size;i++) { //@Debug
//            cout << ships[temp.first - 1].pegs[i] << " ";  //@Debug
//        }                                                  //@Debug
//        cout << endl;
        checkSunk(ships[temp.first - 1]);
        setShipMap(shipMap,index,9,8);
    }
    string tCoord = "(" + to_string(r) + "," + to_string(c) + ")";
    shots.root = shots.insert(shots.root,tCoord);
}

bool battleship::checkLoss(ship* ships) {
    for(int i = 0;i < 5;i++) {
        if(ships[i].sunk == false) {
            return false;
        }
    }
    return true;
}

bool battleship::checkSunk(ship& ship) {
    
    for(int i =0;i < ship.size;i++) {
        if(ship.pegs[i] == false) {
            
            return false;
        }
    }
    cout << endl << "You sunk ship #" << ship.number << " good job!" << endl;
    ship.sunk = true;
    return true;
}
set<pair<int,int>> battleship::createCoords() {
    
    set<pair<int,int>> temp;
    for(int i =1;i <= 10;i++) {
        for(int j =1;j <= 10;j++) {
            pair<int,int> p = make_pair(i,j);
            temp.insert(p);
        }
    }
    return temp;
}

void battleship::setShipMap(list<pair<int,int>>&v,int i,int x,int y) {
    list<pair<int,int>>::iterator it = v.begin();
    for(int n =0;n < i;n++) {
        it++;
    }
    *it = make_pair(x,y);   
}

void battleship::printShipMap(list<pair<int,int>>&v, bool owner) {
    
    for(int i = 0;i < 9;i++) {
        cout << "=  =  ";
    }
    cout  << "=";
    list<pair<int,int>>::iterator it;
    int count = 0;
    for(it = v.begin();it != v.end();it++) {
        if( count % 10 == 0) {
            cout << endl << endl;
        }
        count++;
        pair<int,int> temp = *it;
        if(temp.first != 0 && temp.first != 8 && temp.first !=9) {
            if(owner) {
                cout << temp.first;
            }
            else {
                cout << "-";
            }
        }
        else if (temp.first == 9) {
            cout << "X";
        }
        else if (temp.first == 8) {
            cout << "O";
        }
        else {
            cout << "-";
        }
        cout << "     ";
    }
    cout  << endl;
    for(int i = 0;i < 9;i++) {
        cout << "=  =  ";
    }
    cout  << "=" << endl;
    cout << endl << endl;
}
void battleship::printCoords(set<pair<int,int>>&v) {
    
    set<pair<int,int>>::iterator it;
    int count = 0;
    for(it = v.begin();it != v.end();it++) {
        if( count % 10 == 0) {
            cout << endl;
        }
        pair<int,int> temp = *it;
        count++;
        cout << "(" << temp.first << "," << temp.second << ")  ";
    }
    cout << endl << endl;
}
