#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[1001]={0,1,2,2,4,2,6,2};
	for(int i=8;i<1001;i++)
	{
		for(int j=i/2;j>0;j--)
		{
			if(i%j==0){a[i]+=a[j];}
			else{}
			
		}
		a[i]++;
	}
	
	cout<<a[n];
	return 0;
}
