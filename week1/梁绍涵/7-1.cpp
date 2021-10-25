#include<bits/stdc++.h>
using namespace std;
int main()
{
 	int n;
	string a;
	cin>>n>>a;
	while(n--)
	{
		int ans=0;
		string b;
		cin>>b;
		for(int i=0;i<a.size();i++)
		{
			int k=0,flag=0,num=b.size();
			if(a[i]==b[0])
			{
				while(num--)
				{
					if(a[i+k]==b[k])
					{
						k++;
					}
					else
					{
						k=0;
						flag=1;
						break;
					}
				}
				if(flag==0) ans++;
			}
			
		}
		cout<<ans<<endl;
	} 
}
