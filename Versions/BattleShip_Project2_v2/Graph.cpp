/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Graph.cpp
 * Author: Austin
 * 
 * Created on December 2, 2022, 3:21 PM
 */

#include "Graph.h"

Graph::Graph(int V) {
        this->V = V;
        l = new list<int>[V];
}
void Graph::addEdge(int x,int y) {       
        l[x].push_back(y);
        l[y].push_back(x);
}
void Graph::printGraph() {
        for(int i =0;i < V;i++) {
            for(int nbr:l[i]) {
                cout <<nbr<<",";
            }
            cout << endl;
        }
}
bool Graph::findNode(int x ,int y) {
        for(int i =0;i < V;i++) {
            for(int nbr:l[i]) {
                if(x == i && nbr == y) {
                    return true;
                }
            }
        } 
        return false;
}
