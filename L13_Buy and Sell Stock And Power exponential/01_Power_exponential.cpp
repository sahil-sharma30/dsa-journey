#include <iostream>
using namespace std;

class Solution
{
public:
    double pow(double x, long long n)
    {
        long long BF = n;
        double ans = 1;
        if (n < 0)
        {
            x = 1 / x;
            BF = -BF;
        }

        while (BF > 0)
        {
            if (BF % 2 == 1)
            {
                ans *= x;
            }
            x *= x;
            BF /= 2;
        }
        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.pow(2, 15) << endl;

    return 0;
}
