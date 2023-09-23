/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Node.h
 * Author: Austin
 *
 * Created on December 1, 2022, 8:37 PM
 */

#ifndef NODE_H
#define NODE_H

#include <string>


using namespace std;


struct Node{
    string data;
    Node *next = NULL;
};

#endif /* NODE_H */

