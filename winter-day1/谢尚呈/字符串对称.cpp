#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string stri;
	cin>>stri;
	int to=stri.length();
	for(int i=0; i<=to/2; i++)
	if(stri[i]!=stri[to-i-1])
	{
		cout<<"no";
		return 0;
	}
	cout<<"yes";
	return 0;
}
