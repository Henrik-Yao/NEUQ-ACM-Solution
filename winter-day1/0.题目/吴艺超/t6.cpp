#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[1000005];
int main()
{
	scanf("%s",a+1);
	int len=strlen(a+1);
	for(int i=1;i<=len/2;i++)
	{
		if(a[i]!=a[len-i+1])
		{
			cout<<"no";
			return 0;
		}
	}
	cout<<"yes";
	return 0;
}
