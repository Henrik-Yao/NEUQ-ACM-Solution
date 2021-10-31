#include<bits/stdc++.h> 
using namespace std;
const int M=1000001;
int c[M];
int find(int l,int r,int g);
int main()
{
	int n,a,i;
	cin>>n>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cout<<find(1,n,a)<<endl;
	return 0;
}
int find(int l,int r,int g)//ÖÐ·Ö 
{
	while(l<=r)
	{
		int middle=(l+r)/2;
		if(g>c[middle])
		{
			l=middle+1;
		}
		else
		{
			r=middle-1;
		}
	}
	return l;
}

