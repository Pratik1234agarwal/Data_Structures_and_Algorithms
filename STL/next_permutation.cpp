#include <bits/stdc++.h>
using namespace std;


void print(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=1;i<=n;i++){
        arr[i-1] = i;
    }
    
    do{
        print(arr);
    }while(next_permutation(arr.begin(),arr.end()));
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t;cin>>_t;while(_t--)
    solve();
}