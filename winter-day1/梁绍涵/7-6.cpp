#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,temp=0;
	string a;
	cin>>a;
	for(i=0,j=a.size()-1;i<j;i++,j--)
	{
		if(a[i]==a[j]) continue;
		else
		{
			temp=-1;
			break;
		}
	}
	if(temp==0)
	cout<<"yes";
	else
	cout<<"no";
}
