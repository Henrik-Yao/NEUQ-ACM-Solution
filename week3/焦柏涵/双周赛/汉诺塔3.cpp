#include <iostream>
using namespace std;
long long hannuo(int n)//������int�Ļ��᲻���� 
{
	if(n==1)
	{
		return 2;
	}
	else
	{
		return 3*hannuo(n-1)+2;
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		cout<<hannuo(n)<<endl;
	}
}
