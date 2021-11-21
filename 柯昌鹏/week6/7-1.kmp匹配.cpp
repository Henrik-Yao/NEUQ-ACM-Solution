#include<bits/stdc++.h>
using namespace std;
int ne[1000000];
string t,p;
void next()
{
	int i=0,j=-1;
	ne[0]=-1;
	while(i<p.size())
	{
		if(j==-1||p[i]==p[j])
		{
			i++;
			j++;
			ne[i]=j;
		}
		else
		j=ne[j];
	}
}
int  kmp()
{
	int sum=0,i=0,j=0;
	while(i<t.size())
	{
		if(j==-1||t[i]==p[j])
		{
			j++;
			i++;
			
		}
		else j=ne[j];
		if(j==p.size()) sum++;
	}
	return sum;
}
int main()
{
	cin>>t>>p;
	next();
	cout<<kmp()<<'\n';
	return 0;
}