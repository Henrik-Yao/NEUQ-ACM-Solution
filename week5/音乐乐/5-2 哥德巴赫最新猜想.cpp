#include<bits/stdc++.h>
using namespace std;
bool check(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long num;
		cin>>num;
		if(num%2==0)
		cout<<"2"<<endl;
		else
		if(check(num))
		cout<<"1"<<endl;
		else
		if(check(num-2))
		cout<<"2"<<endl;
		else
		cout<<"3"<<endl;
	}
	return 0;
}
