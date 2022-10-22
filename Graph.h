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
#include <queue>
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
    int INF;
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
    INF = 999;
}
//==========================================//
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
//==========================================//
void Graph::shortestPath(int start)
{
    // Create PQ that stores vertices
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > PQ;

    // Distance vector
    vector<int> distance(V, INF);

    PQ.push(make_pair(0, start));
    distance[start] = 0;

    // Loop until PQ becomes empty
    while (!PQ.empty())
    {
        //gets minimum distance vertex
        int u = PQ.top().second;
        PQ.pop();
        //iterator for custom list
        list< pair<int, int> >::iterator i;
        for(i = adj[u].begin(); i!= adj[u].end(); i++)
        {
            // Get vertex and weight
            int v = i->first;
            int weight = i->second;

            // Relaxation
            if (distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                PQ.push(make_pair(distance[v], v));
            }
        }
    }
    // Display paths
    cout << "Vertex Distances from start" << endl;
    for(int i=0; i<V; i++)
        cout << i << "\t\t" << distance[i] << endl;
}
#endif