/*
    Maximillian Chalitsios
    1808500
    Dijkstra's algorithm implementation in C++
    10/22/2022
*/
//==========================================//
#include "Graph.h"
//==========================================//
int main()
{
    int V = 9;
    Graph g(V);
    //initializing graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    //Shortest path
    g.shortestPath(2);
    return 0;
}
//==========================================//
