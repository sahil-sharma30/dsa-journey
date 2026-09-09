#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int val)
    {
        data = val;
        next = prev = NULL;
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
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_between(int pos, int val)
    {
        if (pos < 0)
        {
            cout << "Invalid Position!" << endl;
            return;
        }
        else if (pos == 0)
        {
            push_front(val);
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)  // Drive to pos - 1
            {
                if (temp == NULL)
                {
                    cout << "Invalid Position!" << endl;
                    return;
                }
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "Invalid Position!" << endl;
                return;
            }
            if (temp == tail)
            {
                push_back(val);
                return;
            }

            // 4-pointer middle rewire
            Node *newNode = new Node(val);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            newNode->next->prev = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "No Node to pop!" << endl;
        }
        else if (head == tail)
        {
            Node *temp = head;
            head = tail = NULL;
            delete temp;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void pop_back()
    {
        if (tail == NULL)
        {
            cout << "No Node to pop!" << endl;
        }
        else if (head == tail)
        {
            Node *temp = tail;
            head = tail = NULL;
            delete temp;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
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

    void print_reverse()
    {
        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    List mylist;

    mylist.push_back(20);
    mylist.push_back(30);
    mylist.push_front(10);
    mylist.push_front(5);
    mylist.push_between(2, 15);
    mylist.push_between(4, 25);

    mylist.print_list();
    mylist.print_reverse();

    mylist.pop_front();
    mylist.pop_back();

    mylist.print_list();

    return 0;
}