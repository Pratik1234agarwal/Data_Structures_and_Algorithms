#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m,f,r;
    cin>>m>>f>>r;
    if(m==-1 || f==-1){
        cout<<"F"<<endl;
        return;
    }
    int total =  m+f;
    if(total >= 80){
        cout<<"A";
    }
    else if(total < 80 && total >= 65){cout<<"B";}
    else if(total <65 && total >= 50){cout<<"C";}
    else if(total < 50 && total >= 30){
        if(r >= 50){
            cout<<"C";
        }else{
            cout<<"D";
        }
    }
    else{
        cout<<"F";
    }
    cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}