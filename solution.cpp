/*
    Maximillian Chalitsios
    1808500
    Dijkstra's algorithm implementation in C++
    10/22/2022
*/
//==========================================//
#include <iostream>
using namespace std;

//==========================================//
// FUNCTIONS DECLARATIONS
void dijkstra(bool visited[], int distance[], int V, int G[][100], int parent[]);
int getNearest(bool visited[], int distance[], int V);
//==========================================//
int main()
{
    // Graph, Vertex, distance matrix variables
    int V, start, G[100][100];
    int distance[100];

    // For visited nodes
    bool visited[100] = {0};

    int parent[100];

    // Initialize distances from start node and parent array
    for (int i=0; i<V; i++)
    {
        distance[i] = INFINITY;
        parent[i] = i;
    }
        
    distance[start] = 0;
    
//TODO: CHANGE BELOW TO STATIC DATA
    cin >> V;

    for(int i=0; i<V; i++)
        for(int j=0; j < V; j++)
            cin >> G[i][j];

    cin >> start;



    return 0;
}
//==========================================//
void dijkstra(bool visited[], int distance[], int V, int G[][100], int parent[])
{
    // V-1 because last node will be remaining node
    for (int i=0; i < V-1; i++)
    {
        int nearest = getNearest(visited, distance, V);
        visited[nearest] = true;

        for(int adj = 0; adj < V; adj++)
        {
            // If a nearest node
            if ((G[nearest][adj] != INFINITY) && (distance[adj] < distance[nearest] + G[nearest][adj]))
            {
                //update the distance of adjacent node
                distance[adj] = distance[nearest] + G[nearest][adj];
                //update parent node
            }

        }

    }
}
//==========================================//
// Returns nearest unvisited node by calculating minimum value of distance
int getNearest(bool visited[], int distance[], int V)
{
    int minvalue = INFINITY;
    int minnode = 0;
    for(int i=0; i< V; i++)
    {
        if (!visited[i] && distance[i] < minvalue)
        {
            // update minvalue
            minvalue = distance[i];
            minnode = i;
        }
    }
    return minnode;
}
//==========================================//

