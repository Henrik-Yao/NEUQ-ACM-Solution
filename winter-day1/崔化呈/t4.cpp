#include<bits/stdc++.h>
using namespace std;
const int M=1e6+50;
int main()
{
	int a[M],b[M/2],c[M/2],t,n=0,m=0,l=0;
	while(cin>>t)
	{
		a[n++]=t;
		if(t%2){b[m++]=t;}
		else{c[l++]=t;}
	}
	sort(a,a+n);
    sort(b,b+m);
    sort(c,c+l);
	for(int i=0;i<n;i++)
	{
        if(i==n-1){cout<<a[i]<<endl;}
        else{cout<<a[i]<<"->";}
		
	}
	for(int i=0;i<m;i++)
	{
		if(i==m-1){cout<<b[i];}
        else{cout<<b[i]<<"->";}
	}
    if(l!=0){cout<<endl;}
	for(int i=0;i<l;i++)
	{
		if(i==l-1){cout<<c[i];}
        else{cout<<c[i]<<"->";}
	}
	return 0;
}
