#include<bits/stdc++.h>
using namespace std;
int ori;
int sea(int n)
{
	if(n==1) return 1;
	int ans=0;
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			ans+=sea(i);	
		}
	}
	return ans+1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>ori;
	cout<<sea(ori); 
}