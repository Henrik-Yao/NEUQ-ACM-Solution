#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string a;
	cin>>n>>a;
	int b=a.length();
	for(int o=1;o<=n;o++)
	{
		int sum=0;
		string x;
		cin>>x;
		int y=x.length();
		for(int i=0;i<b;i++)
		{
			if(x[0]==a[i])
			{	
				bool p=true;
				for(int j=1;j<y;j++)
				{
					if(x[j]!=a[i+j]) p=false;
				}
				if(p==true) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
