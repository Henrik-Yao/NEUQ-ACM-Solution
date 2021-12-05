#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t[1050];
	string a,b;
	while((getline(cin,a))&&(getline(cin,b)))
	{
		for(int i=0;i<b.size();i++)
		{
			t[b[i]]++;
		}
		for(int i=0;i<a.size();i++)
		{
			if(!t[a[i]]){cout<<a[i];}
		}
		memset(t,0,sizeof(t));
		cout<<endl;
	}
	return 0;
}
