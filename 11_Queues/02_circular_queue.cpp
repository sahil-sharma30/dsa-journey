#include <iostream>
using namespace std;

class CircularQueue
{
    int arr[5];
    int front = -1;
    int rear = -1;
    int N = 5;

public:
    void enqueue(int val)
    {
        // 1. Check if full
        if (((rear + 1) % N) == front)
        {
            cout << "Queue is Full!" << endl;
            return;
        }

        // 2. Check if it's the very first element
        if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = val;
            cout << val << " enqueued." << endl;
            return;
        }

        // 3. Normal insertion 
        rear = (rear + 1) % N; // Assign back to rear 
        arr[rear] = val;
        cout << val << " enqueued." << endl;
    }

    void dequeue()
    {
        // 1. Check if empty
        if (front == -1)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        // 2. Check if it's the LAST element leaving
        if (front == rear)
        {
            cout << arr[front] << " dequeued. Queue is now totally empty." << endl;
            front = -1;
            rear = -1;
            return; 
        }

        // 3. Normal deletion 
        cout << arr[front] << " dequeued." << endl;
        front = (front + 1) % N; // Assign back to front!
    }

    void getFront()
    {
        if (front == -1) {
            cout << "Queue is empty, no front element." << endl;
            return;
        }
        cout << "Current Front: " << arr[front] << endl;
    }
};

int main()
{
    CircularQueue cq;

    cout << " Filling Queue " << endl;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50); // Queue is now full

    cout << "\n Testing Circular Wrap " << endl;
    cq.dequeue();   // Removes 10, freeing up index 0
    cq.enqueue(60); // Successfully stores 60 at index 0 

    cout << "\n Final State " << endl;
    cq.getFront();  // 20

    return 0;
}
// :)