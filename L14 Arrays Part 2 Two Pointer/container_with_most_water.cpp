#include <iostream>
#include <algorithm> // Required for min() and max()
using namespace std;

int main() {
    int ht[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int w, h;
    
    int lp = 0; 
    int rp = 8; 
    int maxWater = 0;
    
    while (lp < rp) {
        // 1. Calculate physical dimensions
        w = rp - lp; 
        h = min(ht[lp], ht[rp]);
        
        // 2. Update maximum water found
        int curWater = w * h;
        maxWater = max(maxWater, curWater);
        
        // 3. Squeeze inward by abandoning the shorter wall
        ht[lp] < ht[rp] ? lp++ : rp--;
    }
    
    cout << "The maximum water trapped is: " << maxWater << " units." << endl;
    
    return 0;
}
