#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int _t;
    cin >> _t;
    while(_t--){
        int a,b;
        cin >> a >>b;
        int t;
        t = a;
        a = b;
        b = t;
        cout<<a<<" "<<b<<endl;
    }
}