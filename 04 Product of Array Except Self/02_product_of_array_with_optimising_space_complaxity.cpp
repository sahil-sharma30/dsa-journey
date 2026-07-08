#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            right *= nums[i+1];
            ans[i] *= right;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = s.productExceptSelf(nums);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}

