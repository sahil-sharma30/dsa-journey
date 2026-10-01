#include <iostream>
using namespace std;

// Connection (Linked List Node)
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
    int V;            // Total number of vertices
    vertex **adjList; // Array of head pointers

    Graph(int vertices)
    {
        V = vertices;

        // Create the array and initialize empty (NULL)
        adjList = new vertex *[V];
        for (int i = 0; i < V; i++)
        {
            adjList[i] = NULL;
        }
    }

    void addEdge(int u, int v)
    {
        // 1. Connection from 'u' to 'v' (Insert at the front)
        vertex *newVertex = new vertex(v);
        newVertex->next = adjList[u];
        adjList[u] = newVertex;

        // 2. Connection from 'v' back to 'u' (Undirected graph)
        vertex *newVertex2 = new vertex(u);
        newVertex2->next = adjList[v];
        adjList[v] = newVertex2;
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " is connected to ";

            // Start at the head of vertex i's list and walk to the end
            vertex *temp = adjList[i];
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next; // Move to the next record
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5); // Create a graph with 5 vertices (0 through 4)

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}