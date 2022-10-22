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
    int infinity = 999;
    // Graph, Vertex, distance matrix variables
    int V, start;
    int distance[100];
    int G[100][100] = 
    {
        {0, 4, 999, 999, 999, 999, 999, 8, 999},
        {4, 0, 8, 999, 999, 999, 999, 8, 999},
        {999, 8, 0, 7, 999, 4, 999, 999, 2},
        {999, 999, 7, 0, 9, 14, 999, 999, 999},
        {999, 999, 999, 9, 0, 10, 999, 999, 999},
        {999, 999, 4, 14, 10, 0, 2, 999, 999},
        {999, 999, 999, 999, 999, 2, 0, 1, 6},
        {8, 11, 999, 999, 999, 999, 1, 0, 7},
        {999, 999, 2, 999, 999, 999, 6, 7, 0},
    };

    // For visited nodes
    bool visited[100] = {0};

    int parent[100];

    // Initialize distances from start node and parent array
    for (int i=0; i<V; i++)
    {
        distance[i] = infinity;
        parent[i] = i;
    }
    //Number of vertices
    V = 9;
    cout << "Number of vertices: " << V << endl;
    cout << "Start node: ";
    cin >> start;
        
    distance[start] = 0;
    
//uncomment below for manual inputs: CHANGE BELOW TO STATIC DATA
    
    // for(int i=0; i<V; i++)
    //     for(int j=0; j < V; j++)
    //         cin >> G[i][j];


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
    int infinity = 999;
    // V-1 because last node will be remaining node
    for (int i=0; i < V-1; i++)
    {
        int nearest = getNearest(visited, distance, V);
        visited[nearest] = true;

        for(int adj = 0; adj < V; adj++)
        {
            // If a nearest node
            if ((G[nearest][adj] != infinity) && (distance[adj] < distance[nearest] + G[nearest][adj]))
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
    int infinity = 999;
    int minvalue = infinity;
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


/*
inputs for costs in G
  0     4   999   999   999   999   999     8   999
  4     0     8   999   999   999   999     8   999
999     8     0     7   999     4   999   999     2
999   999     7     0     9    14   999   999   999
999   999   999     9     0    10   999   999   999
999   999     4    14    10     0     2   999   999
999   999   999   999   999     2     0     1     6
  8    11   999   999   999   999     1     0     7
999   999     2   999   999   999     6     7     0
*/

