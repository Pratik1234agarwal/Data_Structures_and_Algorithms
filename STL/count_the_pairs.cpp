#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr.begin(),arr.end());
    
    int start = 0 ,end = n-1;
    long long int ans = 0;
    while(start<end){
        int s = arr[start] + arr[end];
        if(s <= x){
            int nNums = end - start;
            ans += 2 * nNums;
            start++;
        }else{
            end--;
        }
    }
    
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);int _t;
    cin>>_t;while(_t--)
    solve();
}