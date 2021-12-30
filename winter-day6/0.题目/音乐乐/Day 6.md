# Day 6

---

## 1.直接插入排序

“直接插入排序”

## 2.成绩排序

“成绩排序”

## 3.统计工龄

“统计工龄”

## 4.最接近神的人

就是输出一个数列的逆序数。为什么是逆序数？（转自某谷）

首先，显然排好序的序列逆序对数一定是 0。

对于i, 和i+1, 显然如果a[i] <= a[i+1] 那么交换这两个数是多余的。因为不管后面怎么交换，最终a[i]一定在a[i+1]前面，如果交换这两个，就会增加a[i]到a[i+1]的前面的交换次数。

对于i,和j, 设i<j且a[i] > a[j], 那么最终a[j]会交换到a[i]前面, 因为只能两两相邻交换，a[i]和a[j]肯定也会交换，否则a[j]无法到a[i]前面, 因为a[j]不可能跳过a[i]。

交换两个相邻的数逆序对数会 -1。显然若a[i] > a[i+1] 交换是它们会减少1个逆序对，由于a[i]和a[i+1]中间没有数，所以不会影响其他逆序对。导致逆序对数会减少1。

既然，任意两个逆序对都要交换，并且每次交换后逆序对数都会减少1，最终的逆序对数是0，那么肯定要交换的个数就是全部逆序对的个数。

归并排序的时候可以顺便计算出逆序数。

```c++
#include<iostream>
using namespace std;
long long a[500005],temp[500005];
long long cnt=0;
void merge(int left,int mid,int right)
{
	int i=left,j=mid+1,k=left;
	while(i<=mid&&j<=right)
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			cnt+=mid-i+1;
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		k++;
		i++;
	}
	while(j<=right)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
	for(i=left;i<=right;i++)
	{
		a[i]=temp[i];
	}
}

int paixu(int left,int right)
{
	if(left>=right)
	return cnt;
	int mid=(left+right)>>1;
	paixu(left,mid);
	paixu(mid+1,right);
	merge(left,mid,right);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	    cin>>a[i];
	paixu(1,n);
	cout<<cnt;
	return 0;
}

```



## 5.堆排序

就堆排序捏，比其他排序稍微复杂一点捏，三言两语讲不清楚捏，STL里面貌似也有heap的相关操作，但是不知道为什么我老是只能输出两行，所以算了。。。

```C++
#include <bits/stdc++.h>
using namespace std;


void display(int a[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int a[], int x, int y) {
    int key  = a[x];
    a[x] = a[y];
    a[y] = key;
}

void Down(int a[], int i, int n) { // 最后结果就是大顶堆
    int parent = i;                    // 父节点下标
    int child  = 2 * i + 1;            // 子节点下标
    while (child < n) {
        if (child + 1 < n && a[child] < a[child + 1]) { // 判断子节点那个大，大的与父节点比较
            child++;
        }
        if (a[parent] < a[child]) { // 判断父节点是否小于子节点
            swap(a, parent, child);     // 交换父节点和子节点
            parent = child;                 // 子节点下标 赋给 父节点下标
        }
        child = child * 2 + 1; // 换行，比较下面的父节点和子节点
    }
}

void BuildHeap(int a[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) { // 倒数第二排开始, 创建大顶堆，必须从下往上比较
        Down(a, i, size);                 // 否则有的不符合大顶堆定义
    }
}

void HeapSort(int a[], int size) {
    BuildHeap(a, size); // 初始化堆
    display(a, size);   // 查看初始化结果
    for (int i = size - 1; i > 0; i--) 
    {
        swap(a, 0, i); // 交换顶点和第 i 个数据
        Down(a, 0, i); // 重新建立大顶堆
        display(a, size);
    }
}

int main() 
{
    int n,array[1001],i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>array[i];
    HeapSort(array,n);
    return 0;
}
```



## 6.快速排序

有两种快排打法，另一种貌似不行。

```C++
#include<bits/stdc++.h>
using namespace std;
int a[1001],N;
void print(int *arr)
{
	for(int i=1;i<=N;i++)
		printf("%d ",arr[i]);
	cout<<endl;
}
void qsort(int l,int r)
{
	if(l>=r) return;
	else
	{
		int i=l;
		int j=r;
		int t=a[l];
		while(i<j)
        {
		    while(i<j&&a[j]>t)
			    j--;
		    while(i<j&&a[i]<=t)
			    i++;
		    swap(a[i],a[j]);
	    }
	    swap(a[i],a[l]);
	    print(a);
	    qsort(l,i-1);
	    qsort(i+1,r);
	}
}
int main()
{
	int i;
	cin>>N;
	for(i=1;i<=N;i++)
		cin>>a[i];
	qsort(1,N);
	print(a);
	return 0;
}

```

