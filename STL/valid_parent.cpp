#include <bits/stdc++.h>
using namespace std;

void solve(){
    string str;
    cin>>str;
    int depth = 0;
    int ans = 0;
    for(auto ch:str){
        if(ch == '('){
            depth++;
        }else{
            depth--;
        }
        
        // If depth is negative, we need to add a bracket
        if(depth<0){
            depth = 0;
            ans++;
        }
    }
    
    if(depth>0){
        ans += depth;
    }
    
    cout<<ans<<endl;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
}