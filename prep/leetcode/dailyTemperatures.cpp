// https://leetcode.com/problems/daily-temperatures/
#include <bits/stdc++.h>
using namespace std;

/**
 * This is the concept of a Monotonic Stack https://labuladong.gitbook.io/algo-en/ii.-data-structure/monotonicstack
 * Monotonic stack is actually a stack. It just uses some ingenious logic to keep the elements in the stack orderly 
 * (monotone increasing or monotone decreasing) after each new element putting into the stack.
 * Well,sounds like a heap? No, monotonic stack is not widely used. It only deals with one typical problem, which is called Next Greater Element
*/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &t)
    {
        vector<int> ans(t.size());
        std::stack<int> s;

        for (int i = 0; i < t.size(); i++)
        {
            while (!s.empty() && t[i] > t[s.top()])
            {
                int x = s.top();
                s.pop();
                ans[x] = i - x;
            }
            s.push(i);
        }
        return ans;
    }
};