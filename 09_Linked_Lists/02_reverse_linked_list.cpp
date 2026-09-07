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

    // Reversing a Linked List
    Node *reverse()
    {
        Node *Curr = head;
        Node *Prev = NULL;
        Node *Next = NULL;

        while (Curr != NULL)
        {
            Next = Curr->next; // 1. Scout ahead to save the rest of the train
            Curr->next = Prev; // 2. Break the link and rewire backwards
            Prev = Curr;       // 3. Move the Prev forward
            Curr = Next;       // 4. Move the Curr forward
        }
        
        tail = head; // 5. Old front is officially the new back
        head = Prev; // 6. Old back is officially the new front
        
        return head;
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

    mylist.reverse();
    mylist.print_list();

    return 0;
}