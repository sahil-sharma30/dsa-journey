#include <iostream>
using namespace std;

// 1. The blueprint
// Every box has two rooms: data and the map to the next box .
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL; // By default, the map points to nothing (end of the line)
    }
};

int main()
{
    // 2. Creating the boxes/nodes
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // 3. Linking the chains
    head->next = second;
    second->next = third;

    cout << "Linked List" << endl;

    // 4. The traversal
    // NEVER move 'head' or you lose the list! Create a temporary runner.
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next; // No temp++
    }

    return 0;
}