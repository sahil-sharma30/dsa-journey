#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{

    int prices[] = {7, 1, 5, 3, 6, 4};
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < 6; i++)
    {
        minPrice = min(prices[i], minPrice);
        int todayprofit = prices[i] - minPrice;
        maxProfit = max(maxProfit, todayprofit);
    }

    cout << "The maximum profit is: " << maxProfit << endl;

    return 0;
}