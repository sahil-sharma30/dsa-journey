#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V]; // Array of linked lists
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u); // Undirected graph
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " is connected to: ";

            for (int neighbor : l[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    ~Graph()
    {
        delete[] l;
    }
};

int main()
{
    Graph g(5);

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