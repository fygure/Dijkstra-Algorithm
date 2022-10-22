/*
    Maximillian Chalitsios
    1808500
    Dijkstra's algorithm implementation in C++
    10/22/2022
*/
//==========================================//
#ifndef GRAPH_H
#define GRAPH_H
//==========================================//
#include <iostream>
#include <utility>
#include <list>
using namespace std;
//==========================================//
// This class represents a directed graph using
// adjacency list representation
class Graph
{
private:
    // Number of vertices
    int V;

    //Store vertex and weight pair for every edge
    list< pair<int, int> >* adj;

public:
    //Constructor
    Graph(int _V);

    //Add edge to graph
    // u = starting node; v = destination node; w = weight of edge
    void addEdge(int u, int v, int w);

    //Prints shortest path from start
    void shortestPath(int s);
};
//==========================================//
Graph::Graph(int _V)
{
    V = _V;
    adj = new list< pair<int, int> >[V];
}
//==========================================//
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
//==========================================//










#endif