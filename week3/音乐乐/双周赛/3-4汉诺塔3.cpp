#include<iostream>
using namespace std;

int main()
{
	long long hanoi[36];
    int t,i;
	hanoi[1]=2;
	for(i=2;i<=35;i++)
	{
		hanoi[i]=3*hanoi[i-1]+2;
	}
	while(cin>>t)
	{
		cout<<hanoi[t]<<endl;
	}
	return 0;
}
