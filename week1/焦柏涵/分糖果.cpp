#include <iostream>
using namespace std;
int z=1; 
int dark(int n)
{
	//int b;
	for(int i=n-1;i>=1;i--)
	{
		//b=i;
	    if(n%i==0&&i!=1)
		{
			z++;
			dark(i);
		}
		else if(i==1)
		{
			z++;
		}
	}
	return z;
}
int main()
{
	int n;
	cin>>n;
	int m=dark(n);
	cout<<m;
 } 
