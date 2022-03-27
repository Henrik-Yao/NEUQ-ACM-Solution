#include <bits/stdc++.h>
using namespace std;
bool sushu(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	 if(x%i==0) return 0;
	return 1;
}
int main()
{
	int n;
	cin>>n;
	while(n)
	{
		int x;
		cin>>x;
		if(x%2==0) cout<<2<<endl;
		else
		{
			if(sushu(x)) cout<<1<<endl;
			else if(sushu(x-2)) cout<<2<<endl;//奇数=2+一个素数 
			else cout<<3<<endl;//奇数=一个素数+一个偶数=三个素数 
		}
		n--;
	}
	return 0;
}
