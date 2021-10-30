#include<bits/stdc++.h>
using namespace std;
void hn(int k,string one,string two,string three)
{
	if(k==1)
	{
		cout<<one<<"->"<<three<<endl;
		return ;
	}
	else
	hn(k-1,one,three,two);
	cout<<one<<"->"<<three<<endl;
	hn(k-1,two,one,three);
}
int main()
{
	int n;
	cin>>n;
	string a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	hn(n,a,b,c);
}
