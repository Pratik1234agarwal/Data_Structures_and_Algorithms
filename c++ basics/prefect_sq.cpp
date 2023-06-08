#include <bits/stdc++.h>
using namespace std;

void solve(){
    int q,n;
    cin >> q >> n;
    int f = 0;
    if(q==1){
        for(int i=1;i*i<=n;i++){
            if(i*i == n){
                cout<<"YES"<<endl;
                f=1;
                break;
            }
        }
        if(f==0)
        cout<<"NO"<<endl;
    }else{
        for(int i=1;i*i*i<=n;i++){
            if(i*i*i == n){
                cout<<"YES"<<endl;
                f=1;
                break;
            }
        }
        if(f==0)
        cout<<"NO"<<endl;
    }
    
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}