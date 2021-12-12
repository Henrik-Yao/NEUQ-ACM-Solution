#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int findmax(int l,int r)
{
    int s=l+1;
    for(int i=l;i<=r;i++)
    {
        if(a[l]<a[i])
        {
            a[l]=a[i];
            s=i;
        }
    }
    return s;
}
int nmd(int l,int r)
{
   
    for(int i=l;i<=r;i++)
        if(a[l]<a[i]+i-l)
            l=i;
    return l;
}
int main()
{
    int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
    cin>>a[i];
    int k=0;
    int c=1;
    while(k+a[k]<n-1)
    {
        int t=a[k];
        int m;
        m=findmax(k,a[k]+k);
        k=nmd(m,t+k);
        c++;
    }
    //puts("%d",c);
    printf("%d\n",c);
    return 0;
}
