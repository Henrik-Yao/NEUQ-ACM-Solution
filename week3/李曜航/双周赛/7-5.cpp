#include <bits/stdc++.h>
using namespace std;
int read()
{
    char c = getchar(); int f = 1, x = 0;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=c-'0'+x*10;c=getchar();}
    return f*x;
}
int n,m;
int a[1000];
int main()
{
    int t = read();
    
    
    while(t--)
    {
        memset(a,0,sizeof(a));
        m = read();
        for(int i=1;i<=m;i++)
            a[i] = read();
        n = read();
        for(int i=m+1;i<=m+n;i++)
            a[i] = read();
        
        sort(a+1,a+1+n+m);
        for(int i=1;i<n+m;i++)
            printf("%d ",a[i]);
	    cout<<a[m+n]<<endl;
    }
    
	
}

