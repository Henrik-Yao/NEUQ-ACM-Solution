#include<bits/stdc++.h>
using namespace std;
int n;
string a;
int main()
{
	cin>>n;
	cin>>a;
	int la=a.length();
	while(n--)
	{
		int ans=0;
		string b;
		cin>>b;
		int lb=b.length();
		for(int i=0;i<la;i++)
		{
			if(a[i]==b[0])
			{
				int flag=0;
				for(int j=0;j<lb;j++)
				{
					if(a[i+j]!=b[j])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
