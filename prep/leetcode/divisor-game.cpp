// https://leetcode.com/problems/divisor-game/submissions/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int *arr;
public:
    bool fn(int n) {
       if(n<=1)return false;
        
       if(arr[n] != -1)
           return arr[n];
        
        for(int i=1;i<=n/2;i++){
            if(n%i==0 && !fn(n-i)){
                    arr[i] = 1;
                    return true;}
            
        }
        arr[n] = 0;
        return false;
    }
    
    bool divisorGame(int n){
        arr = new int[n+1];
        memset(this->arr, -1, sizeof(int)*(n+1));
        return fn(n);
    }
};
