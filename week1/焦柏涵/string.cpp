#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int a=0,i,n;
	char b[100000],c[30];
	cin>>n>>b;
	for(i=0;i<n;i++)
	{
		a=0;
		cin>>c;
		int x=strlen(c),y=strlen(b);
		for(int j=0;j<y;j++)
		{
			int o=0;
			for(int l=0;l<x;l++)
			{
				if(c[l]==b[j+o])
				{
					o++;
				}
			}
			if(o==x) a++;
		}
		cout<<a<<endl;
	}
}
