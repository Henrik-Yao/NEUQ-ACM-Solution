#include<bits/stdc++.h>
using namespace std;
bool judge(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0)
	return false;
	return true;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>c;
		if(c%2==0)
		{
			cout<<"2"<<endl;
		}
		else if(judge(c))
		cout<<"1"<<endl;
		else if(!judge(c)&&judge(c-2))
		cout<<"2"<<endl;
		else
		cout<<"3"<<endl;
	}
}
