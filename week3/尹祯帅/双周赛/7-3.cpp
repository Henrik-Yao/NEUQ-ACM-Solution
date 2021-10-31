#include<bits/stdc++.h>
using namespace std;
long long  hnt(int n)
{
	if(n==0) return 0;
    if (n==1) return 2;
	return 3*hnt(n-1) +2;
}
int main()
{
	int n;
	
	while(~scanf("%d",&n)) cout<<hnt(n)<<'\n';
	
}
