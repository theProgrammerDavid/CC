#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        
        for(auto i:tokens){
            
            if(i=="+" || i=="-" || i=="/" || i=="*"){
                int op1 = s.top();
                s.pop();
                
                int op2 = s.top();
                s.pop();
                
                int temp = 0;
                if(i=="+")temp = op1+op2;
                else if(i=="-") temp=op2-op1;
                else if(i=="*")temp = op2*op1;
                else if(i=="/")temp = op2/op1;
                    
                s.push(temp);
            }
            else{
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};