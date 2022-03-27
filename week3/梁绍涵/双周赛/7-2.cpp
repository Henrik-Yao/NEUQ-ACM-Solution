#include<bits/stdc++.h>
using namespace std;
void hnt(string from,string mid,string to,int num)
{
	if(num==1)
	{
		cout<<from<<"->"<<to<<endl;
		return;
	}
	hnt(from,to,mid,num-1);
	cout<<from<<"->"<<to<<endl;
	hnt(mid,from,to,num-1);
}
int main()
{
	int n;string a,b,c;
	cin>>n;cin>>a>>b>>c;
	hnt(a,b,c,n);
}
