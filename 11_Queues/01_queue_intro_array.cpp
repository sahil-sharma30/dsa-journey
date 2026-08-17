#include <iostream>
using namespace std;

class Queue
{
    int arr[100];
    int frontIndex = -1;
    int rearIndex = -1;

public:
    // Add element to the back
    void enqueue(int val)
    {
        if (rearIndex >= 99)
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        // Handle the very first insertion
        if (frontIndex == -1)
        {
            frontIndex = 0;
        }

        rearIndex++;
        arr[rearIndex] = val;
        cout << "Element: " << val << " added in the Queue" << endl;
    }

    // Remove element from the front
    void dequeue()
    {
        if (frontIndex == -1 || frontIndex > rearIndex)
        {
            cout << "Queue Underflow! , No element in the Queue" << endl;
            return;
        }

        frontIndex++; // Move pointer forward instead of deleting
        cout << "Front element removed from the Queue" << endl;
    }

    // Get front element
    void front()
    {
        if (frontIndex == -1 || frontIndex > rearIndex)
        {
            cout << "Queue Underflow! , No element in the Queue" << endl;
            return;
        }

        cout << "Front: " << arr[frontIndex] << endl;
    }

    // Check if queue is empty
    bool empty()
    {
        return (frontIndex == -1 || frontIndex > rearIndex);
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.front();
    q.dequeue();

    cout << "--- After dequeue ---" << endl;
    q.front();

    return 0;
}