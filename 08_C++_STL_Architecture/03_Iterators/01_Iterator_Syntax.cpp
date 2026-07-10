#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {10, 20, 30, 40, 50};

    // vec.begin() points to the very first element (10).
    cout << "vec.begin: " << *(vec.begin()) << endl;

    // CRITICAL: vec.end() points strictly OUTSIDE (one memory space past) the last element.
    // We must subtract 1 to safely read the actual last element (50).
    cout << "vec.end (last element): " << *(vec.end() - 1) << endl;

    cout << "\n--- Forward Traversal ---" << endl;

    // This is the traditional, explicit way to declare an iterator.
    vector<int>::iterator ite;
    for (ite = vec.begin(); ite != vec.end(); ite++)
    {
        cout << *(ite) << " ";
    }
    cout << endl;

    cout << "\n--- Reverse Traversal ---" << endl;

    // 'auto' dynamically figures out the correct type (reverse_iterator in this case).
    // This saves us from explicitly typing out vector<int>::reverse_iterator.
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;

    return 0;
}