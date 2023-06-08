#include <bits/stdc++.h>
using namespace std;

int check(int a[],int b[],int n,int m,int x,int k){
    // add check for zero
    int totalLessThanX = 0;
    for(int i=0;i<n;i++){
        if(a[i] == 0){
            totalLessThanX += m;
        }else{
            int r = (int) x - a[i];
            auto it = upper_bound(b,b+m,r);
            int count = it - b;
            totalLessThanX += count;
        }
    }
    
    if(totalLessThanX == k){
        return 1;
    }else{
        return 0;
    }
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
	int a[n],b[m];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    
    sort(a,a+n);
    sort(b,b+m);
    
    int left = a[0]+b[0],right = a[n-1]+b[m-1],ans = right;
    while(left<=right){
        int mid = (left + right)/2;
        if(check(a,b,n,m,mid,k)){
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