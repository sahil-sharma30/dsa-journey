#include <iostream>
using namespace std;

// src: Source rod
// helper: Helper rod
// dest: Destination rod
void hanoi(int n, char src, char helper, char dest)
{
    // 1. BASE CASE: Only 1 disk left to move
    if (n == 1)
    {
        cout << "Move disc " << n << " from rod " << src << " to rod " << dest << endl;
        return;
    }

    // STEP 1: Move top n-1 disks from Source to Helper, using Dest as temporary storage.
    hanoi(n - 1, src, dest, helper);

    // STEP 2: Move the actual largest disk remaining from Source to Dest.
    cout << "Move disc " << n << " from rod " << src << " to rod " << dest << endl;

    // STEP 3: Move the n-1 disks sitting on the Helper to Dest, using Source as temporary storage.
    hanoi(n - 1, helper, src, dest);
}

int main()
{
    int n = 3; // Number of disks
    
    char S = 'S'; 
    char H = 'H'; 
    char D = 'D';

    cout << "Tower of Hanoi solution for " << n << " disks:\n";
    cout << endl;
    
    hanoi(n, S, H, D);

    return 0;
}