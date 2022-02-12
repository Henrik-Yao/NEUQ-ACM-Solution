//������ģ�� 
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
void adjustHeap(int arr[],int l,int r)//��lΪ���ڵ㽨������� 
{
	int left=l*2;//���� 
	int right=l*2+1;//�Һ��� 
	int now=l;//�� 
	if(left<=r&&arr[left]>arr[now])
	{
		now=left;
	}
	if(right<=r&&arr[right]>arr[now])
	{
		//Ҫ�������ӽڵ��и�����Ǹ����� 
		if(arr[right]>arr[left])now=right;
	}
	if(now!=l)
	{
		swap(arr[l],arr[now]);
		adjustHeap(arr,now,r);
	}
}
void buildMaxHeap(int arr[],int l,int r)//������һ������� 
{
	for(int i=r/2;i>=l;i--)
	{
		adjustHeap(arr,i,r);
	}
}
void heapSort(int arr[],int l,int r)//������ 
{
	buildMaxHeap(arr,l,r);//���� 
	print(arr,l,r);//�����һ������� 
	for(int i=r;i>l;i--)
	{
		swap(arr[i],arr[l]);//�Ѷ���δ�����Ԫ�������һ������ 
		adjustHeap(arr,l,i-1);//��δ�����Ԫ�������½�������� 
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
