#include<iostream>
#include<cstring>
using namespace std;
string a[2][100003];
int main()
{
	bool b=0;
	string c;
	int n,m,t;
	cin>>n>>m;
	for (int i=0;i<n;i++)
	cin>>a[0][i]>>a[1][i];
	for (int j=0;j<m;j++)
	{
		cin>>c;
		for (int i=0;i<n;i++)
		if (a[1][i]==c)
		{
		b=1;
		t=i;
		break;
	 }
		else
		b=0;
		if (b==1)
		cout<<a[0][t]<<endl;
		else
		cout<<"eh"<<endl;
	}
}
