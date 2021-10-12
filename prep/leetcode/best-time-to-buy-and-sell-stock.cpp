#include <bits/stdc++.h>
using namespace std;

//bruteforce
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i=0;i<prices.size();i++){

            for(int j=i+1;j<prices.size();j++){
                int profit = prices[j] - prices[i];
                if(profit > ans)
                    ans = profit;
            }
        }
        return ans;
    }
};

// optimised
//

class SolutionOptimised {
public:
    int maxProfit(vector<int>& prices) {
        int minProf = INT_MAX;
        int maxProf = 0;
        
        for(int i=0;i<prices.size();i++){
            if (prices[i]< minProf){
                minProf = prices[i];
            }
            else if(prices[i] - minProf > maxProf){
                maxProf = prices[i] - minProf;
            }
        }
        
        return maxProf;
    }
};
