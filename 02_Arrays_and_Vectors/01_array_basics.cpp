#include <iostream>
#include <climits>
using namespace std;

// Array initialization and loops
void arraySyntaxAndLoops()
{
    int marks[5] = {99, 100, 54, 36, 88};
    int size = 5;

    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << marks[i] << " ";
    }
    cout << endl;
}

// Finding smallest and largest value
void findSmallestLargest(int arr[], int size)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << "Smallest value: " << smallest << endl;
    cout << "Largest value: " << largest << endl;
}

// Reversing an array
void reverseArray(int arr[], int size)
{
    int st = 0;
    int end = size - 1;
    int temp;
    while (st < end)
    {
        temp = arr[st];
        arr[st] = arr[end];
        arr[end] = temp;
        st++;
        end--;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    arraySyntaxAndLoops();
    findSmallestLargest(arr, size);
    reverseArray(arr, size);

    return 0;
}