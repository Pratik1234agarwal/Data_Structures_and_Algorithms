#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve(){
    int n;
    lli target;
    cin>>n>>target;
    lli arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+n);
    
	lli sum = INT_MAX;
    for(int i=0;i<n-2;i++){
        int p1=i+1,p2=n-1;
        //lli t = target - arr[i];
        cout<<"========= I: "<<i<<endl;
        while(p1<n && p2 >=0){
        	lli s = arr[p1] + arr[p2] + arr[i];
            cout<<"p1: "<<p1<<" p2: "<<p2<<endl;
            sum = min(sum,abs(s - target));
            if(s > target){
                p2--;
            }else if(s < target){
                p1++;
            }else{
                p1++;
                p2--;
            }
        }
    }
    
    cout<<sum<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}