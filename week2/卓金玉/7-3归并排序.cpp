#include<iostream>
using namespace std;
void mergeSort(int a[],int begin,int end);
void merge(int a[],int begin,int mid,int end);
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
void mergeSort(int a[],int begin,int end)
{
	if(end-begin==1)
	{
		if(a[begin]>a[end])
		{
			swap(a[begin],a[end]);
		}
	}
	else if(begin==end)
	{
		return;
	}
	else
	{
		mergeSort(a,begin,(begin+end)/2);
		mergeSort(a,(end+begin)/2+1,end);
		merge(a,begin,(begin+end)/2,end);
	}
}
void merge(int a[],int begin,int mid,int end)
{
    int len=end-begin+1;
    int temp[len];
    int i=0;
    int lBegin=begin;
    int rBegin=mid+1;
    while(lBegin<=mid && rBegin<=end)
    {
    	if(a[lBegin]<=a[rBegin])
    	{
    		temp[i]=a[lBegin];
    		lBegin++;
		}
		else
		{
			temp[i]=a[rBegin];
			rBegin++;
		}
		i++;
	}
    while(lBegin<=mid)
    {
    	temp[i]=a[lBegin];
    	lBegin++;
    	i++;
	}
    while(rBegin<=end)
	{
    	temp[i]=a[rBegin];
    	rBegin++;
    	i++;
	}
    for(i=0;i<len;++i)
    {
    	a[begin+i]=temp[i];
	}
}
