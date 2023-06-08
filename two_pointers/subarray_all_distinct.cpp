#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    set<int> ss;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ss.insert(arr[i]);
    }
    
    int k = ss.size();
    
    int head = -1,tail =0;
    int ans = INT_MAX;
    int distinct = 0;
    map<int,int> st;
    while(tail<n){
        // move head as far as possible
        while(head+1 < n && distinct < k){
            head++;
            if(st[arr[head]] == 0)distinct++;
            st[arr[head]]++;
        }
        
        if(distinct == k)
        ans = min(ans,head-tail+1);
		

        if(head>=tail){
            st[arr[tail]]--;
            if(st[arr[tail]] == 0)distinct--;
            tail++;
        }else{
           // st.erase(arr[tail]);
            tail++;
            head = tail-1;
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