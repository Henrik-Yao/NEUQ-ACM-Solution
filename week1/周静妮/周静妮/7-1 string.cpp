#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 4e6+1e2;
char s[maxn];
int main()
{
	int n,m,n1,l,n2;
	string a,b;
	cin>>n; 
	cin>>s;
	n1= strlen(s);
	for (int i=0;i<n;i++)
	{
		int n2=0;
		cin>>a;
		int l= a.length();
		for (int i=0;i<=n1-l+1;i++)
		{
		b.clear();
		for (int j=i-1;j<i+l-1;j++) b+=s[j];
		if (a==b) ++n2;
		}
		cout<<n2;
		if (i!=n-1) cout<<endl;
	}
	return 0;
}
