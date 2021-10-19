#include <iostream>
using namespace std;
int main()
{
    int m,n,i,j,l;
	cin>>m>>n;
	int a[n][2],b[m+1];
	for(i=0;i<n;i++) 
		cin>>a[i][0]>>a[i][1];
	cin>>l;
	for(i=0;i<l;i++)
	{
		int s,x;
		cin>>s;
		for(j=1;j<=m;j++)
		b[j]=1;
		for(j=0;j<s;j++)
		{
			cin>>x;
			b[x]=0;
		}
		int f=0;
		for(j=0;j<n;j++)
			if(b[a[j][0]]&&b[a[j][1]])
			{
				f=1;
				break;
			}
		if(f==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}
