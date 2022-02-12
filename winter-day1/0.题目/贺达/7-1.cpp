#include<bits/stdc++.h>
using namespace std;

int n,q;
long long a[1000005];//树状数组

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int i)
{
    for(int j=x;j<=n;j=j+lowbit(j))
    {
        a[j]=a[j]+i;
    }
}

long long getsum(int x)
{
    long long sum=0;
    for(int i=x;i>0;i=i-lowbit(i))
    {
        sum=sum+a[i];
    }
    return sum;
}

int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int ans;
        cin>>ans;
        update(i,ans);
    }
    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1)
        {
            update(y,z);
        }
        else
        {
            cout<<getsum(z)-getsum(y-1)<<endl;
        }
    }
}
