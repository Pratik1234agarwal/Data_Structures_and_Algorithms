#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int,string>> arr(n);
    for(int i=0;i<n;i++){
        string name;int roll;
        cin>>name>>roll;
        arr[i].first = roll;
        arr[i].second = name;
    }
    
    sort(arr.begin(),arr.end());
    // Printing
    for(int i=0;i<n;i++){
        cout<<arr[i].second<<" "<<arr[i].first<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}