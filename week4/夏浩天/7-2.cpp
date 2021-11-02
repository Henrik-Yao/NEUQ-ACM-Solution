#include<iostream>
#include<string.h>
using namespace std;
int dg(int n)
{
    if(n==1||n==2)return 1;
    else
        return dg(n-1)+dg(n-2);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
            if(m==1)
    {
cout<<"0";return 0;}
        int sum=dg(m);
        cout<<sum<<endl;
    }
}