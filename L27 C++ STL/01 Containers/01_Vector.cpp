#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec1(3, 10);

    cout << "vec1: ";
    for (int val : vec1)
        cout << val << " ";
    cout << endl;

    // 2. Copy constructor: Creates vec2 as a complete, independent clone of vec1
    vector<int> vec2(vec1);

    cout << "vec2: ";
    for (int val : vec2)
        cout << val << " ";
    cout << endl;

    return 0;
}