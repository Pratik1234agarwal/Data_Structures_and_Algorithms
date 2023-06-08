#include <bits/stdc++.h>
using namespace std;

void solve(){
    int q;
    cin >> q;
    queue<int> qu;
    while(q--){
        string word;
        int x;
        cin>>word;
        if(word == "add"){
            cin>>x;
            qu.push(x);
        }else if(word == "remove"){
            if(!qu.empty()){
                qu.pop();
            }
        }else{
            if(qu.empty()){
               cout<<0<<endl; 
            }else{
                cout<<qu.front()<<endl;
            }
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}