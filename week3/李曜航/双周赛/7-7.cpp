#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N = 1000010;
int n,a[N],c[N];
ll ans;

void merge(int start,int end)
{
    if(start==end)  
		return;
    int mid=(start+end)/2;
    int i=start,j=mid+1,point=start;
    merge(start,mid),merge(mid+1,end);
    while(i<=mid&&j<=end)
    {
        if(a[i]<=a[j])
    		c[point++]=a[i++];
    	else
        {
    		c[point++]=a[j++];
            ans+=mid-i+1;
        }
    }
    	
    
    while(i<=mid)
    	c[point++]=a[i++];
    while(j<=end)
    	c[point++]=a[j++];
    for(int l=start;l<=end;l++)
    	a[l]=c[l];
} 

int main()
{
    n = read();
    for(int i=1;i<=n;i++)
    	a[i] = read();
    merge(1,n);
    cout<<ans;
    return 0;
}


