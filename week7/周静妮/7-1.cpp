#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,i,j;
	string a[10000],b[10000],str;
	cin>>n>>m;
	for(i=0;i<n;i++)
	cin>>a[i]>>b[i];
	while(m--)
	{
		bool flag=1;
		cin>>str;
		for(j=0;j<n;j++)
		if(str==b[j])
		{
			flag=0;
			break;
		}
		if(flag)	cout<<"eh";
		else cout<<a[j];
		cout<<endl;
	};
	return 0;
}
