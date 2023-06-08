#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int check(lli a[],int n,lli x,int k){
    int paintersRequired = 1;
	lli paintedSum = 0;
    for(int i=0;i<n;i++){
        if(paintedSum + a[i] > x ){
            paintedSum = a[i];
            paintersRequired ++;
        }else{
            paintedSum += a[i];
        }
    }
    
    if(paintersRequired <= k )return 1;
    else return 0;
    
}

void solve(){
    int n,k;
    cin>>n>>k;
	lli a[n];
    lli sum = 0,m = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        m = max(m,a[i]); 
        sum+=a[i];
    }

    
    lli left = m,right = sum,ans = sum;
    while(left<=right){
        lli mid = (left + right)/2;
        if(check(a,n,mid,k)){
            ans = mid;
            right = mid - 1;
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