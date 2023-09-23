/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   HashTable.cpp
 * Author: Austin
 * 
 * Created on December 1, 2022, 6:53 PM
 */

#include "HashTable.h"

HashTable::HashTable() {
}

HashTable::HashTable(const HashTable& orig) {
}

HashTable::~HashTable() {
}

Node **HashTable::insrtNode(string *arr, int n, int size){
    Node **ndArr = new Node*[size];
    int hash;
    Node *head;
    
    for (int i = 0; i < size; ++i) {
        *(ndArr + i) = new Node;
    }
    for(int i = 0; i < n; i++){
        hash = ClayHash(arr[i]) % size;
        head = ndArr[hash];
        while(ndArr[hash]->next){
            ndArr[hash] = ndArr[hash]->next;
        }
        ndArr[hash]->data = arr[i];    
        ndArr[hash]->next = new Node;
        ndArr[hash] = head;
    }
    
    return ndArr;
}

unsigned int HashTable::ClayHash(string q)   
{
   unsigned int seed = 1337; 
   unsigned int hash = 0;

   for(int i = 0; i < q.length(); i++)
   {
      hash = hash + q[i];
   }
   hash = (hash * seed);

   return hash;
    
}

