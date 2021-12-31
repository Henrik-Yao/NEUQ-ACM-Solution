#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,len1,len2;
	string a,b;
	cin>>n;
	cin>>a;
	len1=a.length();
	while(n--)
	{
		int i,count=0;
		string c;
		cin>>b;
		len2=b.length();
		for(i=0;i<=len1-len2;i++)
		{
			c=a.substr(i,len2);
			if (c==b)
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
