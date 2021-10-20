#include<iostream>
using namespace std;
unsigned int a[100010],temp[100010];

void merge(int left,int mid,int right)
{
	int i=left,j=mid+1,k=left;
	while(i<=mid&&j<=right)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
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

void paixu(int left,int right)
{
	if(left>=right)
	return;
	int mid=(left+right)/2;
	paixu(left,mid);
	paixu(mid+1,right);
	merge(left,mid,right);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	paixu(1,n);
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
