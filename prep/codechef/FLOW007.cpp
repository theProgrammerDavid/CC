#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    
    while(T--){
        int x;
        cin>>x;
        int rev=0;
        
        while(x>0){
            rev = (x%10) + rev*10;
            x/=10;
        }
        
        cout<<rev<<"\n";
    }
	// your code goes here
	return 0;
}
