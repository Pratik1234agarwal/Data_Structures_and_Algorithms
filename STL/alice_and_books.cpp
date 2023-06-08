#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    multiset<int> arr;
    int greater = 0;
    int c = 1;
    multiset<int>::iterator it;
    for(int i=0;i<n;i++){
        int r;
        cin >> r;
        arr.insert(r);
        if(i==0)it = arr.begin();
        if(r >= c){
            greater++;
        }
        
        
        // 
        if(greater >= c){
            // Found B book of B pages where  B=c
            cout<<c<<" ";
            c++;
            // find no of book >= new c value
            // update greater
            auto temp = arr.lower_bound(c);
            if(temp == arr.end()){
                c--;
            }else{
            int tt = 0;
            auto dis = it;
            while(dis!=arr.end() || temp!=arr.end() || dis!=temp){
                tt++;
                temp++;
            }
            // cout<<tt<<endl;
            //int tt = distance(temp,it);
            if(tt>=0){
            greater -= (tt);
        	it = temp;}
            if(greater<0)greater = 0;
            }
            
        }else{
            cout<<c-1<<" ";
        }
    }
    cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}