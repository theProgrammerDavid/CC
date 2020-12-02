#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	for(int i=0;i<T;i++){
	    int x,y,z;
	    cin>>x>>y>>z;
	    
	    vector<int> vec;
	    vec.push_back(x);
	    vec.push_back(y);
	    vec.push_back(z);
	    
	    sort(vec.begin(), vec.end());
	    cout<<vec.at(1)<<"\n";
	    
	}
	return 0;
}
