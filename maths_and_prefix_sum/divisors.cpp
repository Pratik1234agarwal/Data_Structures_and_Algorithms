#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve(){
    int n;
    cin>>n;
    
    int nDivisors = 0;
    set<int> st;
    int len = (int)sqrt(n);
    for(int i=1;i<=len;i++){
        if(n%i==0){
            if(i==len && i*i == n){
                nDivisors++;
            }else{
                nDivisors+=2;
            }
        }
    }
    
    cout<<nDivisors<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
};