#include <bits/stdc++.h>
using namespace std;
/*int max(int *a,int n){
    int max=-10000;
    for(int m=0;m<n;m++)
    {
        if(a[m]>max) max=a[m];
    }
    return max;
}*/
int main ()
{
    int n,T,v,t,max=-1000000;
    cin>>n>>T;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>v>>t;
        if(t>T) a[i]=v-(t-T);
        else a[i]=v;

    }
    for(int m=0;m<n;m++)
    {
     if(a[m]>max) max=a[m];
	}
    cout<<max;
    return 0;
}
