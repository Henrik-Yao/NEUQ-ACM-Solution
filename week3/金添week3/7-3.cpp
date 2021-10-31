#include <bits/stdc++.h>
using namespace std;
char ch[100];
long long ans(int n)
{
	 int sum=0;
	 if(n==1)
	 return 2;
	 else
     return ans(n-1)*3+2;	 
}
int main()
{
	int n;
    while(cin>>n)
    {
    	cout<<ans(n)<<endl;
	}
	
	return 0;
}
