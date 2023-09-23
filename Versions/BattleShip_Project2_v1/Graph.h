/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Graph.h
 * Author: Austin
 *
 * Created on December 2, 2022, 3:21 PM
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <iostream>


using namespace std;

class Graph {
private:
    int V; 
    list<int> *l;
public:
    Graph(int V);
    void addEdge(int x,int y);
    void printGraph();
    bool findNode(int x ,int y);
};

#endif /* GRAPH_H */

