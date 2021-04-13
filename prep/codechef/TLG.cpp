#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t N;
    int leader = 0;
    int cum1=0, cum2=0;
    int lead = 0;
    cin>>N;
    // vector<int> p1(N), p2(N);
    for(int i=0;i<N;i++){
        // cin>>p1[i]>>p2[i];

        int p1,p2;
        cin>>p1>>p2;
        cum1+=p1;
        cum2+=p2;

        if(cum1 > cum2 && cum1-cum2 > lead){
            lead = cum1 - cum2;
            leader = 1;
        }
        else{
            lead = cum2 - cum1;
            leader = 2;
        }
    }

    cout<<leader<<" "<<lead<<"\n";
    return 0;
}