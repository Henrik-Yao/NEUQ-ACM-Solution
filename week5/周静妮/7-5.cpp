#include <bits/stdc++.h>
using namespace std;
const int N=5e4;
int a[N],b[N];
int escape(int m,const int n)
{
	int k,t;
	if( m>=n || m<0 || b[m]==1) return 0;
	else if(a[m]==0) return 1;
	else 
	{
		b[m]=1;
		if( escape(m+a[m],n)==1 ||  escape(m-a[m],n)==1 ) return 1;
		else return 0;
	}
} 
int main()
{
	
	b[N]={0};
	int m,n,i,j,t;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	cin>>m;
	t=escape(m,n);
	if(t) cout<<"True";
	else cout<<"False";
	return 0;
}
