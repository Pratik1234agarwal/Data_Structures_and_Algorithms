#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int check(lli arr[],int x,int n,int k){
    int disStudent = 0;
    int studentSeated = 1;
    for(int i=1;i<n;i++){
        disStudent += arr[i] - arr[i-1];
        if(disStudent >= x){
            studentSeated ++;
            if(studentSeated == k)return 1;
            disStudent = 0;
        }
    }
    
    return 0;
}

void solve(){
    int n,k;
    cin>>n>>k;
    
    lli arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+n);
    
    int left = 0,right = (int)ceil((arr[n-1] - arr[0])/(k-1));
    int ans = right;
    while(left<=right){
        int mid = (left+right)/2;
        if(check(arr,mid,n,k)){
            ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
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