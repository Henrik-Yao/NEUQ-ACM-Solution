#include<bits/stdc++.h>
using namespace std;
int a[100086];
int b[100086];
int flag[100086];
int c; 
int main()
{   
    int k=1,j=1;
    while(cin>>c)
    {
    	a[k]=c;
    	k++;
	}
	sort(a+1,a+k);
	memset(flag,0,k+1);
	for(int i=1;i<=k;i++)
	{
		if(a[i]%2==0)
		{
			b[j]=a[i];
			j++;
			flag[i]=1;
		}
	}
	for(int i=1;i<k-1;i++)
	{
		cout<<a[i]<<"->";
	}
	cout<<a[k-1]<<endl;
	int m=0;
	for(int i=1;i<k-1;i++)
	{   
	 if(flag[i]!=1&&m==0)
	 {
	 	cout<<a[i];
	 	m++;
	 }
	 else if(flag[i]!=1&&m!=0)
	{
	    cout<<"->"<<a[i];
	}
	}
	cout<<endl;
	for(int i=1;i<j-2;i++)
	{
		cout<<b[i]<<"->";
	}
	cout<<b[j-2]<<endl;
	


}
