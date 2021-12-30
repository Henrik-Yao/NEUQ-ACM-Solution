#include<bits/stdc++.h>
using namespace std;
int n,a[1000];
void siftdown(int a[1000],int pos,int size)
{
	int child,temp=a[pos];
	for(;pos*2+1<size;pos=child)
	{
		child=pos*2+1;
		if(child!=size-1&&a[child+1]>a[child])
		{
			child++;
		}
		if(a[child]>temp)
		{
			a[pos]=a[child];
		}
		else
		{
			break;
		}
	}	
	a[pos]=temp;
}
void heapsort(int a[1000])
{
	for(int i=n/2-1;i>=0;i--)
	{
		siftdown(a,i,n);
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}  		
 	cout<<endl;
 	for(int i=n-1;i>0;i--)
 	{
 		swap(a[0],a[i]);
 		siftdown(a,0,i);
		for(int j=0;j<n;j++)
		{
			cout<<a[j]<<" ";
		}
  		cout<<endl;
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	heapsort(a);
	return 0;
}
