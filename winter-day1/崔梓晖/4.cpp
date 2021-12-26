#include <bits/stdc++.h>
using namespace std;
int n,a[1000001];
int main()
{
	int t=0,o=0,j=0;
	while(cin>>n)
	{
		t++;
		a[t]=n;
		if(n%2==0)
		{
			o++;
		}
		else
		j++;
		char ch=getchar();
		if(ch=='\n')
		break;
	}
	sort(a+1,a+t+1);
	cout<<a[1];
	for(int i=2;i<=t;i++)
	{
		cout<<"->"<<a[i];
	}
	cout<<endl;
	
	for(int i=1;i<=t;i++)
	{
		if(a[i]%2!=0)
		{
			j--;
		    if(j!=0)
		    {
		    	cout<<a[i]<<"->";
			}
		    else cout<<a[i];
	    }
	}
	cout<<endl;
	int q=0;
	for(int i=1;i<=t;i++)
	{
		if(a[i]%2==0)
		{
			o--;
			if(o!=0)
			cout<<a[i]<<"->";
			else
			cout<<a[i];
		}
	}
	return 0;
}
