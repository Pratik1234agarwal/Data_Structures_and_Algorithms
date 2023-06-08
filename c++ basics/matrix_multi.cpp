#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,p;
    cin >> n >> m >> p;
    int A[n][m];
    int B[m][p];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            cin>>B[i][j];
        }
    }
    
    // New Matrix is of the dimension n*p
    int s[n][p];
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            int sum = 0;
            for(int k=0;k<m;k++){
                sum += A[i][k]*B[k][j];
            }
            s[i][j] = sum;
        }
    }
    
    //printing the final array 
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;
    while(_t--)
    solve();
}