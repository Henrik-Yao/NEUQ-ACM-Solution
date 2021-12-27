#include <bits/stdc++.h>
using namespace std;
int n;
int zhong[101],hou[101];
void deal(int l1,int r1,int l2,int r2)
{
	if(r1<l1)
	return;
	cout<<hou[r2]<<" ";
	int pos=-1;
	for(int i=l1;i<=r1;i++)
	{
		if(zhong[i]==hou[r2])
		pos=i;
	}
	deal(l1,pos-1,l2,l2+(pos-1-l1));
	deal(pos+1,r1,r2-1-(r1-pos-1),r2-1);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>hou[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>zhong[i];
	}
	deal(0,n-1,0,n-1);
	return 0;
}

