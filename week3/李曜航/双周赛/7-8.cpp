#include <bits/stdc++.h>
using namespace std;
int read()
{
    char c = getchar(); int f = 1, x = 0;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=c-'0'+x*10;c=getchar();}
    return f*x;
}
int n,x;
const int N = 1e6+100;
int a[N];
int find(int l, int r)
{
	if(l==r && x<a[l]) return l;
	if(x==a[l]) return l;
	if(x==a[r]) return r;
	
	if(x<a[l]) return 0;
	if(x>a[r]) return 0;
	int mid = (l+r)/2;
	int a = find(l,mid);
	if(a) return a;
	int b = find(mid+1,r);
	if(b) return b;
}
int main()
{
	n = read(), x = read();
	for(int i=1;i<=n;i++)
		a[i] = read();
	if(x>a[n]){cout<<n+1;return 0;}
	if(x<=a[1]){cout<<"1";return 0;}
	else{
		int pos = find(1,n);
		while(pos>1)
		{
			if(a[pos]==a[pos-1])
				pos--;
			else
			{
				break;
			}
		}
		cout<<pos;
	}
	    
}