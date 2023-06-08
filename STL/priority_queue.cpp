#include <bits/stdc++.h>
#include <map> 
using namespace std;

void solve(){
    int q;
    cin >> q;
    priority_queue<int> st;
    while(q--){
        string word;
        int x;
        cin>>word;
        if(word == "add"){
            cin >> x;
            st.push(x);
        }else if(word == "remove"){
          if(!st.empty()){
              st.pop();
          }
        }
        else if(word == "print"){
        	if(!st.empty()){
                cout<<st.top()<<endl;
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