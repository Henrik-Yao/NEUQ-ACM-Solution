#include<iostream>
using namespace std;
void hnt(string from,string mid,string to,int sum)
{
	if(sum==1)
	cout<<from<<"->"<<to<<endl;
	else
	{
		hnt(from,to,mid,sum-1);
		cout<<from<<"->"<<to<<endl;
		hnt(mid,from,to,sum-1);
	}
	 
}
int main()
{    
	int n;
	string a,b,c;
	cin>>n>>a>>b>>c;
	hnt(a,b,c,n);
}
