#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
	
    int arr[n][m];
    long long sum[n][m];
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    
    // making the sum array 
    sum[0][0] = arr[0][0];
    for(int i=1;i<m;i++){
        sum[0][i]= sum[0][i-1]+arr[0][i];
    }
    for(int i=1;i<n;i++){
        sum[i][0]= sum[i-1][0]+arr[i][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            sum[i][j] = arr[i][j] + 
                sum[i-1][j]+sum[i][j-1]
                -sum[i-1][j-1];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"here"<<endl;
    
    for(int i=1;i<=q;i++){
        int r1,r2,c1,c2;
        r1=r1-1;r2=r2-1;c1=c1-1;c2=c2-1;
        cin>>r1>>c1>>r2>>c2;
        int ans = sum[r2][c2];
        if(c1)ans -= sum[r2][c1-1];
        if(r1)ans -= sum[r1-1][c2];
        if(r1 && c1) ans += sum[r1-1][c1-1];
    	cout<<ans<<endl;
    }
    cout<<"Here"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //while(_t--)
	solve();
}