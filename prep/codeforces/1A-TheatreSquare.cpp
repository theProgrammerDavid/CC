#include <iostream>
#include <math.h>
using namespace std;

int main(){
    unsigned long long m,n,a;
    cin>>n>>m>>a;
    unsigned long long ans = ceil((double)m/a) *ceil((double)n/a);
    cout<<ans<<"\n";
    return 0;
}