#include<iostream>
using namespace std;
int main()
{
	int a,b,bl=1,wc=0;
	while(cin>>a>>b)
	{
		for (int i=a;i<=b;i++)
		{
			for (int j=2;j<i;j++)
			if(i%j==0)
			{
			bl=0;
			break;
		}
		if(bl==1)
		if(wc==0)
		{
			wc=1;
			cout<<i;
		}
		else
		cout<<" "<<i;
		bl=1;
		}
		cout<<endl;
        wc=0;
	 } 
}
