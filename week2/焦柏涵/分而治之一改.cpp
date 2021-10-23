#include <iostream>
using namespace std;
int main()
{
	int n,m,k,a[10001],b[10001];
	cin>>n>>m;
	for(int i=0;i<m;i++) cin>>a[i]>>b[i];
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int np,t[10001],v,p=0;
		cin>>np;
		for(int j=0;j<10001;j++) t[j]=0;
		for(int j=1;j<=np;j++)
		{
			cin>>v;
			t[v]=1;
		}
		for(int j=0;j<m;j++)
		{
			if(t[a[j]]==0&&t[b[j]]==0)
			{
				p=1;
				break;
			}
		}
		if(p==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
