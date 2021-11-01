#include <iostream>
using namespace std;
long long hannuo(int n)//这里用int的话会不够用 
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
