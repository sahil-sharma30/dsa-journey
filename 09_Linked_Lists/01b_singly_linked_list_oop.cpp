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

    // Add in between: Worst-Case Time Complexity: O(n) , Best-Case Time Complexity: O(1)
    void push_between(int pos, int val) // pos meaning indices
    {
        if (pos < 0) // Edge Case: Prevent invalid negative indexes
        {
            cout << "Invalid position!" << endl;
            return;
        }
        else if (pos == 0) // Shortcut: If target is position 0, reuse existing logic
        {
            push_front(val);
        }
        else
        {
            Node *temp = head;
            // Move temp exactly to the node BEFORE the target (pos - 1)
            for (int i = 0; i < pos - 1; i++)
            {
                if (temp == NULL) // Check out-of-bounds positions
                {
                    cout << "Invalid position!" << endl;
                    return;
                }
                temp = temp->next;
            }

            if (temp == NULL) // Prevent off-by-one gaps at the end of the list
            {
                cout << "Invalid position" << endl;
                return;
            }

            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            if (newNode->next == NULL)
            {
                tail = newNode;
            }
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

    // Pop in between
    void pop_between(int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid Position!" << endl;
            return;
        }
        else if (pos == 0)
        {
            pop_front();
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                if (temp == NULL)
                {
                    cout << "Invalid Position" << endl;
                    return;
                }
                temp = temp->next;
            }
            if (temp == NULL || temp->next == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }
            Node *victim = temp->next;
            temp->next = victim->next;

            if (temp->next == NULL)
            {
                tail = temp;
            }

            delete victim;
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

    // Testing insertion
    mylist.push_front(30);
    mylist.push_front(20);
    mylist.push_front(10);
    mylist.push_back(40);
    mylist.push_back(50);
    // Test inserting in the middle
    mylist.push_between(1, 99);

    mylist.print_list();

    // Testing Deletion
    mylist.pop_front();
    mylist.pop_back();
    // Test deleting from the middle
    mylist.pop_between(2);

    mylist.print_list();

    return 0;
}
