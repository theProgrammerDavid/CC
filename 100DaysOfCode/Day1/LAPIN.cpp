#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++){
        string s,s2;
        cin>>s;
        s2=s;
        reverse(s.begin(), s.end());
        if(s==s2)cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}
