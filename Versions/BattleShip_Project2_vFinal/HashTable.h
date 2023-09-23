/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   HashTable.h
 * Author: Austin
 *
 * Created on December 1, 2022, 6:53 PM
 */


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>



#include "Node.h"

using namespace std;

class HashTable {
public:
    HashTable();
    HashTable(const HashTable& orig);
    virtual ~HashTable();
    Node **insrtNode(string *arr, int n, int size);
    unsigned int ClayHash(string q);
   
private:

};

#endif /* HASHTABLE_H */

