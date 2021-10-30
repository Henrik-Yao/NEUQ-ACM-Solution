#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s,a;
	cin>>n;
	cin>>s;
	int x=s.length();//s的长度
	while(n--)
	{
		int z=0;//数量
		cin>>a;
		int y=a.length();
		for(int i=0;i<x;i++)
		{
			if(s[i]==a[0])
			{
				int f=1;
				for(int j=0;j<y;j++)
				{
					if(a[j]!=s[i+j]) f=0;
				}
				if(f==1) z++;
			}
		}
		cout<<z<<endl;
	}
    return 0;
}
