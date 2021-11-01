#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long b[70];
	long long mini;


	b[0]=0; b[1]=1; b[2]=3; b[64]=18433;

	for(int i=3;i<64;i++)
	{
		long long mini=999999,temp;
		for(int j=1;j<i;j++)
		{
			temp=2*b[j]+pow(2,i-j)-1;
		    if(temp<mini)
		    mini = temp;
		}
		b[i] = mini;
	}

	int n;
	while(cin>>n)
	{
		cout<<b[n]<<endl;
	}
	return 0;
}
