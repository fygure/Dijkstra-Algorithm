/*
    Maximillian Chalitsios
    1808500
    Dijkstra's algorithm implementation in C++
    10/22/2022
*/
//==========================================//
#include <iostream>
using namespace std;

#define INFINITY 999;
//==========================================//
// FUNCTIONS DECLARATIONS
void dijkstra(int& V);
int getNearest();
//==========================================//
int main()
{
    // Graph, Vertex, distance matrix variables
    int V, start, G[100][100];
    int distance[100];

    // Initialize distances from start node
    for (int i=0; i<V; i++)
        distance[i] = INFINITY;
    distance[start] = 0;
    



    return 0;
}
//==========================================//
void dijkstra(int& V)
{
    // V-1 because last node will be remaining node
    for (int i=0; i < V-1; i++)
    {
        int nearest = getNearest();
    }
}
//==========================================//
int getNearest()
{

}
//==========================================//

