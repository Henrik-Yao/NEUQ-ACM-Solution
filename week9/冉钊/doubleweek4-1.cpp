#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    int pot[n],x[n-1];
    for(int i=0;i<n;i++){
        cin>>pot[i];
    }
    if(m>=n) cout<<n;
    else{
        sort(pot,pot+n);
        for(int i=0;i<n-1;i++){
            x[i]=pot[i+1]-pot[i]-1;
        }//两个点的间隔是要少1的，因为点自己有1长度；
        sort(x,x+n-1);
        int l=pot[n-1]-pot[0]+1;
        for(int i=1;i<=m-1;i++){
            l-=x[n-2];
            n--;
        }
        cout<<l;
    }//m条线，就是相当于一整个区间，切（m-1）刀来划分区间，即去掉（m-1）个最大数；

    return 0;
}
