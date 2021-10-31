#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int m,n,a[101],b[101],c[201];
		cin>>m;
		for(int j=1;j<=m;j++) cin>>a[j];
		cin>>n;
		for(int j=1;j<=n;j++) cin>>b[j];
		int t=1,s=1,k=1;
		while(t<=m && s<=n)
		{
			if(a[t]<=b[s])
			{
				c[k]=a[t];
				k++;
				t++;
			}
			else
			{
				c[k]=b[s];
				k++;
				s++;
			}
		}
		
		while(t<=m)
		{
			c[k]=a[t];
			k++;
			t++;
		}
		
		while(s<=n)
		{
			c[k]=b[s];
			k++;
			s++;
		}
		
		for(int z=1;z<k;z++)
		{
			cout<<c[z];
			if(z!=k-1) cout<<" ";
		}
        cout<<"\n";
	}
	return 0; 
}
