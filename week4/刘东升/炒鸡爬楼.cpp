#include<bits/stdc++.h>
using namespace std;
const int M=40;
int a[M];
int main()
{
	a[1]=a[2]=1;
	int N,i;
	cin>>N;
	for(i=3;i<41;i++)
	{
		a[i]=a[i-1]+a[i-2];//ÍÆì³²¨ÄÇÆõ 
	}
	a[1]=0;
	while(N--)
	{
		cin>>i;
		cout<<a[i];
		if(N)
		{
			cout<<endl;
		}
	}
}
 
