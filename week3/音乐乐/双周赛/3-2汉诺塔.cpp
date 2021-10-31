#include<bits/stdc++.h>
using namespace std;


void hanoi(int num,string a,string b,string c)
{
	if(num==1)
	cout<<a<<"->"<<c<<endl;
	else
	{
		hanoi(num-1,a,c,b);
		cout<<a<<"->"<<c<<endl;
		hanoi(num-1,b,a,c);
	}
}


int main()
{
	int n; 
	cin>>n;
	string a,b,c;
	cin>>a>>b>>c;
	hanoi(n,a,b,c);
	return 0;
}
