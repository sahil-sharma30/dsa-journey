#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = head; // Points to itself
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head; // Tail must always loop back to new head
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = newNode;
            newNode->next = head; // Points to itself
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // New tail must loop back to the head
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (head == tail) // Only one car left
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (head == tail) // Only one car left
        {
            delete tail;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            // Positioning temp before tail
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;       // Delete old tail
            tail = temp;       // Assign new tail
            tail->next = head; // Rewire the circular loop
        }
    }

    void print_list()
    {
        if (head == NULL)
        {
            cout << "No Node to display!" << endl;
            return; // Guard against empty list crash
        }

        Node *temp = head;
        do // The do-while loop to break the traversal trap
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    CircularList cl;

    cl.push_back(20);
    cl.push_back(30);
    cl.push_front(10);
    cl.push_front(5);

    cout << "Original List: ";
    cl.print_list();

    cl.pop_front();
    cl.pop_back();

    cout << "After Pops: ";
    cl.print_list();

    return 0;
}