#include <iostream>
#include <vector>
using namespace std;

class BinarySearch
{
public:
    void nosearch(const vector<int> &arr, int n)
    {
        bool found = false;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == n)
            {
                cout << arr[i] << " is the matching no. at position "<<i+1 << endl;
                found= true;
            }
        }
        if (!found) {
        cout << "No match." << endl;
    }
    }
};

int main()
{
    BinarySearch b;
    vector<int> arr = {8, 2, 6, 4, 9};

    b.nosearch(arr, 6);

    return 0;
}
