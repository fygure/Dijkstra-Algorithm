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

    dijkstra(visited, distance, V, G, parent);

    // Display data
    cout << "Node:\t\t\tCost : \t\t\tPath";

    for(int i=0; i<V; i++)
    {
        cout << i << "\t\t\t" << distance[i] << "\t\t\t" << " ";

        cout << i << " ";
        int parentnode = parent[i];

        while(parentnode != start)
        {
            cout << " <== " << parentnode << " ";
            parentnode = parent[parentnode];
        }
        cout << endl;

    }


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
                parent[adj] = nearest;
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

