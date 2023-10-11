#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        auto max_element_iter = max_element(nums.begin(), nums.end());
        int max_element_index = max_element_iter - nums.begin();
        int max_element = *max_element_iter;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != max_element && nums[i] * 2 > max_element)
            {
                return -1;
            }
        }
        return max_element_index;
    }
};