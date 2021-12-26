#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int lowbit(int i)
{
     return i&(-i);    
}
void change(int i,int x,int n)
{
    int j;
	for(int j=i;j<=n;j=j+lowbit(j))
	{
        a[j]=a[j]+x;
    }
}
long long Sum(int t)
{
    long long sum=0;
    for(int i=t;i>0;i=i-lowbit(i))
	{
        sum=sum+a[i];
    }
    return sum;
}
int main()
{
	int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
	{
        int x;
        cin>>x;
        change(i,x,n);
    }
    while(q--)
	{
        int j;
        cin>>j;
        if(j==1)
		{
            int i,x;
            cin>>i>>x;
			change(i,x,n);
        }
		else
		{
            int l,r;
            cin>>l>>r;
			cout<<Sum(r)-Sum(l-1)<<endl;
        }
    }
    return 0;
}
