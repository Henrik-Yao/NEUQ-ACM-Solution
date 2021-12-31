#include <bits/stdc++.h>
#define lowbit(i) ((i)&(-i)) 
using namespace std;
const int maxn=1000005;
int n,N;long long int c[maxn];
void add(int x,int v);
long long gSum(int x);
int main()
{
    cin>>n>>N;
    for(int i=1;i<=n;i++)
	{
        int ans;
        cin>>ans;
        add(i,ans);
    }
    while(N--)
	{
        int ope,fir,sec;
        cin>>ope>>fir>>sec;
        if(ope==1)
		{
            add(fir,sec);
        }
		else
		{
            cout<<gSum(sec)-gSum(fir-1)<<endl;
        }
    }
}
void add(int a,int x)
{
    for(int i=a;i<=n;i=i+lowbit(i))
	{
        c[i]=c[i]+x;
    }
}
long long gSum(int x)
{
    long long sum=0;
    for(int i=x;i>0;i=i-lowbit(i))
	{
        sum=sum+c[i];
    }
    return sum;
}

