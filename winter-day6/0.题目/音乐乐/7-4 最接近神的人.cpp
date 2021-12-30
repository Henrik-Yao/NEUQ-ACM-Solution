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

