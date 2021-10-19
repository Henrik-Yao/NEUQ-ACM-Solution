#include<bits/stdc++.h>
using namespace std;
void hannuo(int n,string one,string two,string three)
{
	if(n==1)
	cout<<one<<"->"<<three<<endl;
	else
	{
		hannuo(n-1,one,three,two);
		cout<<one<<"->"<<three<<endl;
		hannuo(n-1,two,one,three);
	}
}
int main()
{
	int n;
	cin>>n;
	string a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	hannuo(n,a,b,c);
	return 0;
}
