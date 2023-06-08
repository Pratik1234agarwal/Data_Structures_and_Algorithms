#include <bits/stdc++.h>
using namespace std;

void solve(){
    int q;
    cin>>q;
    vector<int> arr;
    while(q--){
        string word;
        int x;
        cin>>word;
        if(word == "add"){
            cin>>x;
            arr.push_back(x);
        }else if(word == "remove"){
            if(!arr.empty()){
                arr.pop_back();
            }
        }else if(word == "print"){
            cin>>x;
            if(arr.size()>x){
                cout<<arr[x]<<endl;
            }else{
                cout<<arr[0]<<endl;
            }
        }else{
            cout<<"Command entered clear"<<endl;
            arr[0] = 0;
            arr.clear();

        }
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}