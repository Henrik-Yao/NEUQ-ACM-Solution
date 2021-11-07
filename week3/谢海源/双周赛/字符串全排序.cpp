#include<bits/stdc++.h>
using namespace std;
char a[10005];
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		a[i]=s[i];
	}
	sort(a,a+n);
	do
	{
		for(int i=0;i<n;i++)
		{
			cout<<a[i];
		}
		cout<<endl;
	}while(next_permutation(a,a+n));
	return 0;	
}
