#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int x;
    cin>>x;
    int l=0;
    int r=n-1;
    int m;
    int flag=0;
    int count=0;
    while(l<=r){
        m=(l+r)/2;
        if(a[m]<x)l=m+1;
        else if(a[m]>x)r=m-1;
        count++;
        if(a[m]==x){flag=1;break;}
    }
    if(flag)cout<<m<<endl<<count<<endl;
    else cout<<"-1"<<endl<<count<<endl;;
    return 0;
}
