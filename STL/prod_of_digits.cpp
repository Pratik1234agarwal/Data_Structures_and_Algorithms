#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    long long int MOD = 1000000007;
    long long int prod = 1;
    for(int i=0;i<n;i++){
        int r;
        cin >> r;
        prod = (prod % MOD) * 1ll*(r % MOD);
    }
    cout<<prod<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}