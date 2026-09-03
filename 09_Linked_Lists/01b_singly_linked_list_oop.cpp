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

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

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

    mylist.push_front(30);
    mylist.push_front(20);
    mylist.push_front(10);
    mylist.print_list();

    return 0;
}