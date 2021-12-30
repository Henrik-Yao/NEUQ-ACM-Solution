#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            cout<<a[i];
            if(i!=n)cout<<" ";
        }
        cout<<endl;
        int x;
        cin>>x;
        for(int i=1;i<=x;i++){
            int num;
            cin>>num;
            int flag=0;
            int k;
            for(k=1;k<=n;k++){
                if(a[k]==num){
                    flag=1;
                    break;
                }
            }
                if(flag==1)cout<<k;
                else cout<<"0";
            if(i!=x)cout<<" ";
            
        }
        cout<<endl;
    }
    return 0;
}

