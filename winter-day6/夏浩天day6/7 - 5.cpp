#include<bits/stdc++.h>
using namespace std;

int n,N=1000;
int a[10000];

void HeapAdjust(int a[],int s,int m)         //筛选法调整堆 
{
 	int x=a[s];
 	for(int j=2*s;j<=m;j*=2)
 	{
  		if(j<m && a[j]<a[j+1]) j++;
  		if(x>=a[j])  break;
  		a[s]=a[j];
  		s=j;
 	}
 	a[s]=x;
}

void CreateHeap(int a[])      //建初堆 
{
 	for(int i=n/2;i>0;i--)
 	{
  		HeapAdjust(a,i,n);
 	}
} 

void HeapSort(int a[])          //堆排序实现 
{
 	CreateHeap(a);
 	
 	for(int i=1;i<=n;i++)
  		cout<<a[i]<<" ";
 	cout<<endl;
 	
 	for(int i=n;i>1;i--)
 	{
  		swap(a[1],a[i]);      //交换堆顶记录和子序列最后一个记录   
  		HeapAdjust(a,1,i-1);
  		
  		for(int i=1;i<=n;i++)
   			cout<<a[i]<<" ";
  		cout<<endl;
 	}
}

int main()
{
 	cin>>n;
 	
 	for(int i=1;i<=n;i++)
  		cin>>a[i];
  		
 	HeapSort(a);
 	return 0;
}
