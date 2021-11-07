#include<iostream>
#include<cmath>
using namespace std;

bool fit[10001];

bool fit_n(int x)
{
	int mid=sqrt(x);
	for(int i=2; i<=mid+1; i++)	if(x%i==0)	return	false;
	return true;
}

void begin()
{
	fit[2]=true;
	for(int i=3; i<10001; i++)	fit[i]=fit_n(i);
	return;
}

int main()
{
	begin();
	int a, b;
	bool use1=false;
	while(cin>>a)
	{
		cin>>b;
		bool use2=false;
		
		if(use1)	cout<<endl;
		else	use1=true;
		
		for(int i=a; i<=b; i++)
		{
			if(fit[i])
			if(use2)	cout<<" "<<i;
			else
			{
				use2=true;
				cout<<i;
			}
			else;
		}
	}
	return 0;
}
