//堆排序模板 
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int a[1005];
void print(int arr[],int l,int r)
{
	for(int i=l;i<=r;i++)cout<<arr[i]<<" ";cout<<endl;
}
void adjustHeap(int arr[],int l,int r)//以l为根节点建立大根堆 
{
	int left=l*2;//左孩子 
	int right=l*2+1;//右孩子 
	int now=l;//根 
	if(left<=r&&arr[left]>arr[now])
	{
		now=left;
	}
	if(right<=r&&arr[right]>arr[now])
	{
		//要与左右子节点中更大的那个交换 
		if(arr[right]>arr[left])now=right;
	}
	if(now!=l)
	{
		swap(arr[l],arr[now]);
		adjustHeap(arr,now,r);
	}
}
void buildMaxHeap(int arr[],int l,int r)//建立第一个大根堆 
{
	for(int i=r/2;i>=l;i--)
	{
		adjustHeap(arr,i,r);
	}
}
void heapSort(int arr[],int l,int r)//堆排序 
{
	buildMaxHeap(arr,l,r);//建堆 
	print(arr,l,r);//输出第一个大根堆 
	for(int i=r;i>l;i--)
	{
		swap(arr[i],arr[l]);//堆顶与未排序的元素中最后一个交换 
		adjustHeap(arr,l,i-1);//在未排序的元素中重新建立大根堆 
		print(arr,l,r);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	heapSort(a,1,n);
	
	return 0;
}
