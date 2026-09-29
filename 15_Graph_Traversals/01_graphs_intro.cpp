#include <iostream>
using namespace std;

class vertex
{
public:
    int data;
    vertex *next;

    vertex(int val)
    {
        data = val;
        next = NULL;
    }
};

class Graph
{
public:
    int V;
    vertex **adjList;

    Graph(int vertices)
    {
        V = vertices;

        adjList = new vertex *[V];

        for (int i = 0; i < V; i++)
        {
            adjList[i] = NULL;
        }
    }
};

int main()
{

    return 0;
}