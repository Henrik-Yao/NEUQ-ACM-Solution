#include<bits/stdc++.h>
using namespace std;
long long sum=0;
#define maxn 10000000
int temp[maxn],a[maxn];
void js(int right ,int middle,int left)
{
	int q=right,w=right,e=middle+1;
	while(q<=middle&&e<=left)
	{
		if(a[q]<=a[e]) 
		{
			temp[w]=a[q];
			q++;
			w++;
		}
		else 
		{
			sum+=middle-q+1;
			temp[w]=a[e];
			e++;
			w++;
		}
	}
	while(q<=middle)
	{
		temp[w]=a[q];
		q++;
		w++;
	}
	while(e<=left)
	{
		temp[w]=a[e];
		w++;
		e++;
	}
	for(int i=right;i<=left;i++)
	{
		a[i]=temp[i];
	}
}
void gb(int right,int left)
{
	if(right<left)
	{
		
		int middle =(right+left)/2;
		gb(right,middle);
		gb(middle+1,left);
		js(right,middle,left);
	}
	
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sum=0;
	gb(0,n-1);
	cout<<sum;
	return 0;
 } 
