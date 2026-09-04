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

// 2. The Manager: Tracks front and back of the list
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL; // Start with empty track
    }

    // Add to the front: O(1) Time Complexity
    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL) // If track is empty
        {
            head = tail = newNode;
        }
        else // Link new node to old front
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // Add to the back: O(1) Time Complexity
    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove from the front: O(1) Time Complexity
    void pop_front()
    {
        if (head == NULL) // 0 node scenario
        {
            cout << "No node to pop!" << endl;
            return;
        }
        else if (head == tail) // 1 node scenario
        {
            delete head;
            head = tail = NULL;
            cout << "Linked List Empty" << endl;
            return;
        }
        else // 2+ node scenario
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Remove from the back: O(n) Time Complexity
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "No node to pop!" << endl;
            return;
        }
        else if (head == tail)
        {
            delete tail;
            head = tail = NULL;
            cout << "Linked List Empty" << endl;
            return;
        }
        else
        {
            Node *temp = head; // Start at the front to find the 2nd-last node
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;       // Destroy final node
            tail = temp;       // Update tail to 2nd-last node
            tail->next = NULL; // new end of node
        }
    }

    // The traversal
    void print_list()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    List mylist;

    // 3. Testing the operations 
    mylist.push_front(30);
    mylist.push_front(20);
    mylist.push_front(10);
    mylist.push_back(40);
    mylist.push_back(50);

    mylist.print_list();

    mylist.pop_front();
    mylist.pop_back();

    mylist.print_list();

    return 0;
}
