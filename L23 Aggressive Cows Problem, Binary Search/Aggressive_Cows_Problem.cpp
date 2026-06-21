#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<int> &stalls, int n, int c, int mid) {
    int cowsCount = 1;         
    int lastPos = stalls[0];   

    for(int i=1;i<n;i++){
        if(stalls[i] - lastPos >= mid){
            cowsCount++;
            lastPos = stalls[i];
        }
        if(cowsCount == c){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int n, int c){

    sort(stalls.begin(), stalls.end());

    int st= 1;
    int end = stalls[n-1] - stalls[0];
    int ans = -1;

    while(st<=end){
        int mid = st + (end-st)/2;
        if(isValid(stalls, n, c, mid)){
            ans = mid;
            st = mid + 1;  // Hunt for a LARGER distance
        }
        else{
            end = mid - 1; // Distance too big, make it SMALLER
        }
    }
    return ans;
}

int main(){

    vector<int> stalls = {1, 2, 8, 4, 9};
    int n = stalls.size();
    int c = 3; // 3 Aggressive Cows

    cout << "The maximum possible minimum distance is: " << aggressiveCows(stalls, n, c) << endl;

    return 0;
}
