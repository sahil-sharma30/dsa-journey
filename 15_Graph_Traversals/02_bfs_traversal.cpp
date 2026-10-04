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

    void addEdge(int u, int v)
    {
        // Insert at the front of u's list
        vertex *newVertex = new vertex(v);
        newVertex->next = adjList[u];
        adjList[u] = newVertex;

        // Insert at the front of v's list
        vertex *newVertex2 = new vertex(u);
        newVertex2->next = adjList[v];
        adjList[v] = newVertex2;
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " is connected to ";
            vertex *temp = adjList[i];

            // Traverse list and print
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void bfs(int stVertex)
    {
        // Visited array
        bool *visitedArr = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visitedArr[i] = false;
        }

        // Manual queue
        int *queue = new int[V];
        int front = -1;
        int rear = -1;

        // Mark and push starting vertex
        visitedArr[stVertex] = true;
        if (front == -1)
        {
            front = rear = 0;
            queue[rear] = stVertex;
        }
        else
        {
            rear++;
            queue[rear] = stVertex;
        }

        // Main BFS loop
        while (front != -1)
        {
            // Pop and print current node
            int current = queue[front];
            cout << current << " ";

            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front++;
            }

            // Traverse neighbors
            vertex *temp = adjList[current];
            while (temp != NULL)
            {
                if (visitedArr[temp->data] == false)
                {
                    // Mark neighbor visited
                    visitedArr[temp->data] = true;

                    // Push neighbor to queue
                    if (front == -1)
                    {
                        front = rear = 0;
                        queue[rear] = temp->data;
                    }
                    else
                    {
                        rear++;
                        queue[rear] = temp->data;
                    }
                }
                temp = temp->next;
            }
        }

        // Free memory
        delete[] visitedArr;
        delete[] queue;
    }

    ~Graph()
    {
        // Free every linked list node
        for (int i = 0; i < V; i++)
        {
            vertex *temp = adjList[i];
            while (temp != NULL)
            {
                vertex *nextVertex = temp->next;
                delete temp;
                temp = nextVertex;
            }
        }
        // Free array of pointers
        delete[] adjList;
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
    g.bfs(0);

    return 0;
}