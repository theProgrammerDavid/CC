#include <vector>
#include <numeric>
using namespace std;

class Solution {
    public:
    int pivotIndex(vector<int>& nums) {
        int array_sum = accumulate(nums.begin(), nums.end(), 0);

        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            if (sum == (array_sum - sum - nums[i])) {
                return i;
            }

            sum += nums[i];
        }

        return -1;
    }
};