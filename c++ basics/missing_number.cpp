#include <bits/stdc++.h>
using namespace std;

void solve(){
   int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int b[n-1];
    int c[n-2];
    for(int i=0;i<n-1;i++){
        cin>>b[i];
    }
    for(int i=0;i<n-2;i++){
        cin>>c[i];
    }
    sort(arr,arr+n);
    sort(b,b+(n-1));
    sort(c,c+(n-2));
    int i=0;
    int f=0;
    for(i=0;i<n-1;i++){
        if(arr[i] != b[i]){
            f=1;
            break;
        }
    }
    if(f){
        cout<<arr[i]<<" ";
    }else{
        cout<<arr[n-1]<<" ";
    }
    int j=0;
    for(j=0;j<n-2;j++){
        if(b[j]!=c[j]){
            f=1;
            break;
        }
    }
    if(f){
        cout<<b[j]<<endl;
    }else{
        cout<<b[n-2]<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}