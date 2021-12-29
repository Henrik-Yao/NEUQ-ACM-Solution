# **寒假集训—day6（排序相关）**

## **7-1**

AC代码

~~~cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n;
int a[105];
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			int end=i;//1->end为当前的有序序列 
			int tem=a[end+1];//选择无序部分中第一个，并从有序序列的末尾向前寻找它的位置 
			while(end>=0)
			{
				if(tem<a[end])
				{
					a[end+1]=a[end];
					end--;
				}
				else break;
			}
			a[end+1]=tem;
			for(int j=1;j<n;j++)cout<<a[j]<<" ";cout<<a[n]<<endl;
		}
	}
	return 0;
}

~~~



## **7-2**

用sort的自定义cmp函数

## **7-3**

这不用桶排序都对不起这道题

## **7-4**

运用归并排序求逆序对

为什么是求逆序对：

​		首先，显然排好序的序列逆序对数一定是 0。

​		对于i, 和i+1, 显然如果a[i] <= a[i+1] 那么交换这两个数是多余的。因为不管后面怎么交换，最终a[i]一定在a[i+1]前面，如果交换这两个，就会增加a[i]到a[i+1]的前面的交换次数。

​		对于i,和j, 设i<j且a[i] > a[j], 那么最终a[j]会交换到a[i]前面, 因为只能两两相邻交换，a[i]和a[j]肯定也会交换，否则a[j]无法到a[i]前面, 因为a[j]不可能跳过a[i]。

​		交换两个相邻的数逆序对数会 -1。显然若a[i] > a[i+1] 交换是它们会减少1个逆序对，由于a[i]和a[i+1]中间没有数，所以不会影响其他逆序对。导致逆序对数会减少1。

​		既然，任意两个逆序对都要交换，并且每次交换后逆序对数都会减少1，最终的逆序对数是0，那么肯定要交换的个数就是全部逆序对的个数。



## **7-5**

堆就是一个完全二叉树

在大根堆中，根节点都是当前子树中的最大值

在小根堆中，根节点都是当前子树中的最小值

**堆排序板子**奉上

~~~cpp
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
		//要与左右子节点中更大的那个交换（规范，当然不是更大的那个也可以排出来）
		if(arr[right]>arr[left])now=right;
	}
	if(now!=l)
	{
		swap(arr[l],arr[now]);
		adjustHeap(arr,now,r);//继续向下堆
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
		swap(arr[i],arr[l]);//堆顶与未排序的元素中最后一个交换，完成最大值放在最后，然后未排序的序列变为l->i-1
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
~~~



## **7-6**

**快排板子**奉上

~~~cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n;
int a[1005];
void print(int *arr)
{
	for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
	cout<<endl;
}
void qsort(int *arr,int l,int r)
{
	if(l>=r)return;
	int mid=arr[l];//选择任意一个数作为基准，比它大的数放它右边，小于等于它的数放它左边
    //这里选择当前序列的第一个数为基准
	int i=l,j=r;
	while(i<j)
	{
		while(arr[j]>mid&&i<j)j--;
		while(arr[i]<=mid&&i<j)i++;
		swap(arr[i],arr[j]);
	}
	swap(arr[l],arr[i]);//将基准数放在中间
	print(arr);
	qsort(arr,l,i-1);
	qsort(arr,i+1,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	qsort(a,1,n);
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}

~~~

