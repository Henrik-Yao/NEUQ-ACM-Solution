#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s1;
	cin>>s1;
	int j=s1.size()-1;
	for(int i=0;i<s1.size()/2;i++)
	{
		if(s1[i]==s1[j])
		{
			j--;
			continue;
		}
		else 
		{
			cout<<"no";
			return 0;
	    }
	}
	cout<<"yes";
	return 0;
}
