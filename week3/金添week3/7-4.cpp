#include <bits/stdc++.h>
using namespace std;
long long mini;
long long n;
long long remp;    
long long a[100]={0,1,3,5};
int main()
{
	for(int i=4;i<=64;i++)
    {
    	mini=999999999;
        for(int j=1;j<i;j++)
        {
        	if(a[i-j]*2+pow(2,j)-1<mini)
		    	{
					mini=a[i-j]*2+pow(2,j)-1;
				}
		}
		a[i]=mini;
	}
	while(cin>>n)
	{
		cout<<a[n]<<endl;
	}
	return 0;
}
