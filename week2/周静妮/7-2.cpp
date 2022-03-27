#include <iostream>
#include <string.h>
const int N = 1e4+9;
using namespace std;
int main()
{
	int n,m,j,i,l,t,c,d,k;
	cin>>n>>m;
	int a[N],b[N],e[N];
	for(i=0;i<m;i++)
		cin>>a[i]>>b[i];
	cin>>t;
	for(i=0;i<t;i++)
	{
		memset(e,1,sizeof(e));
		cin>>c;
		l=1;
		for(j=0;j<c;j++)
		{
			cin>>d;
			e[d]=0;
		}
		for(k=0;k<m;k++)
			if(e[a[k]]&&e[b[k]]) l=0;
		if(l==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
