#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long x;
    float b;
    string s;
    getline(cin,s,' ');
    x = stoll(s);
    getline(cin,s);

    int l = s.length();
    int i=0;
    for(i=0;i<l;i++){
        if(s[i] == '.'){
            break;
        }
    }

    long long  y = stoll(s.substr(0,i));
    long long  z = stoll(s.substr(i+1,l-(i+1)));

    string s2 = to_string(x+z) + "." + to_string(x+y);

    cout<<(s2)<<endl;


}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}