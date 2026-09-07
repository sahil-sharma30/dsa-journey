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

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    // Finding the middle of the Linked List
    void middle()
    {
        Node *slow = head;
        Node *fast = head;

        // Fast moves 2x, Slow moves 1x, (&&) for checking either or both conditions
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;       // 1 step
            fast = fast->next->next; // 2 step
        }
        cout << "Middle: " << slow->data << endl;
    }

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

    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);
    mylist.push_back(40);
    mylist.push_back(50);
    mylist.print_list();

    mylist.middle();

    return 0;
}