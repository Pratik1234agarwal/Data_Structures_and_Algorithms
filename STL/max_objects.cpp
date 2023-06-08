// Enter your code below 

#include <bits/stdc++.h>



using namespace std;
#define ll long long int

void solve(){
    int n,q;
    cin>>n>>q;
    vector<ll> prices(n);
    for(int i=0;i<n;i++){
        ll r;
        cin>>r;
        prices[i] = r;
    }
    // sorting the array 
    sort(prices.begin(),prices.end());
    // Building prefix Sum 
    vector<ll> sum(n);
    sum[0] = prices[0];
    for(int i=1;i<n;i++){
        sum[i] = sum[i-1] + prices[i]; 
    }
    
    // Running Queries
    for(int i=1;i<=q;i++){
        ll p;
        cin >> p;
        auto up = upper_bound(sum.begin(),sum.end(),p);
        ll nItems = 0 ;
        if(up-sum.begin() > 0 ){
            nItems = up - sum.begin();
        }
        cout<<nItems<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t;cin>>_t;while(_t--)
    solve();
}