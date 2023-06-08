#include <bits/stdc++.h>
#include <map> 
using namespace std;

void solve(){
    int q;
    cin >> q;
    map<string,int> st;
    while(q--){
        string word;
        int x;
        cin>>word;
        if(word == "add"){
            string name;
            cin>>name;
            cin>>x;
            st[name] = x;
        }else if(word == "erase"){
           string name;
            cin>> name;
            if(st.find(name)!=st.end()){
                st.erase(name);
            }
        }
        else if(word == "print"){
        	string name;
        	cin>> name;
            if(st.find(name) != st.end()){
                cout<<st[name]<<endl;
            }else{
                cout<<0<<endl;
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