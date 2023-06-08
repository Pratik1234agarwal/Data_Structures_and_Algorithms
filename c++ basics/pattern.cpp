#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int _t;
    cin >> _t;
    while(_t--){
        int a,b;
        cin >> a >>b;
        for(int i=1;i<=3*a+1;i++){
            if(i%3==1){
                for(int j=1;j<=b;j++){
                    cout<<"***";
                }
                cout<<"*"<<endl;
            }else{
                for(int j=1;j<=b;j++){
                    cout<<"*..";
                }
                cout<<"*"<<endl;
            }
        }
    }
}