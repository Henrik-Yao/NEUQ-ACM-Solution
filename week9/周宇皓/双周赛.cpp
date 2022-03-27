#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a[205],b[204],m,t;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
sort(a,a+n);
    for(i=1;i<n;i++)
    {
        b[i-1]=a[i]-a[i-1]-1;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            if(b[i]<b[j])
            {
                t=b[i];
                b[i]=b[j];
                b[j]=t;
            }
        }
    }
    t=a[n-1]-a[0]+1;
    for(i=0;i<m-1;i++)
    {
        t=t-b[i];
    }
    printf("%d\n",t);
    }
    return 0;
}

