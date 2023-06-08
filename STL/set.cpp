#include <bits/stdc++.h>
using namespace std;

void solve(){
    int q;
    cin >> q;
    set<int> st;
    while(q--){
        string word;
        int x;
        cin>>word;
        if(word == "add"){
            cin>>x;
            st.insert(x);
        }else if(word == "erase"){
            int x;
            cin>>x;
            if(st.find(x) != st.end()){
                st.erase(x);
            }
        }else if(word == "find"){
            cin>>x;
            if(st.find(x) == st.end()){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }else if(word == "print"){
            for(auto v:st){
                cout<<v<<" ";
            }
            cout<<endl;
        }else{
            st.clear();
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}