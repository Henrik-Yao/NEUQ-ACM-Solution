#include<bits/stdc++.h> 
using namespace std;
unsigned long long a[36];
unsigned long long move(int n);
int main()
{
    int n;
    for(int i=0;i<=35;i++)
	{
		a[i]=move(i);
	}
    while(cin>>n) {
    	cout<<a[n]<< endl;
	}
    return 0;
}
unsigned long long move(int n)//ÕÒ¹æÂÉ 
{
	if(a[n]!=0)
	{
		return a[n];
	}
    if(n==1)
	{
		return 2;
	}
    else
	{
        return move(n-1)+1+move(n-1)+1+move(n-1);
    }
}
