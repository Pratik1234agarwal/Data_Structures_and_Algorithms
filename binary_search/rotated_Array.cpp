#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int check(lli x,lli first){
    if(x<first)return 1;
    return 0;
}

void solve(){
    int n;cin>>n;
    lli arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int left = 0,right=n-1;
    lli ans = 0;
    while(left<=right){
        int mid = (left + right)/2;
        if(check(arr[mid],arr[0])){
            ans = mid;
            right = mid-1;
        }else{
            left = mid + 1;
        }
    }
    
    cout<<ans<<endl;
    
    
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}