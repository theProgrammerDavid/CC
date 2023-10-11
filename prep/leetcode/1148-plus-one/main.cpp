#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry_over = 0;
        if (digits.size() == 1 && digits[0] == 9)
        {
            return {1, 0};
        }
        digits[digits.size() - 1]++;

        for (int i = digits.size() - 1; i > 0; i--)
        {

            carry_over = digits[i] / 10;
            if (carry_over-- == 1)
            {
                digits[i] = 0;
                digits[i - 1]++;
            }
        }

        if (digits[0] == 10)
        {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};