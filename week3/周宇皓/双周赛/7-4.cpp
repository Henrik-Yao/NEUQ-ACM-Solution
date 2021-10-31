#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
	double a[65],d[65];
    d[0]=0;
    d[1]=1;
    for(int i=2;i<=64;i++){
        d[i]=2*d[i-1]+1;
    }
            a[0]=0;
        for(int i=1;i<=64;i++)
            a[i]=2e100;
        for(int i=1;i<=64;i++)
            for(int j=0;j<i;j++){
                 a[i]=min(2*a[j]+d[i-j],a[i]);
            }
    while(cin>>n){

        cout<<a[n]<<endl;
    }
    return 0;
}

