#include<iostream>
#define ll long long
using namespace std;
int n;
int a[1000001];
int b[1000001];
long long tol;


void merge(int arr[],int l,int mid,int r)
{
	int lenth = r - l + 1;
	int i = 0;
    int left = l;
    int right = mid + 1;
	while(left<=mid && right<=r)
	{
		if(arr[left] <= a[right])
		{
            i++;
			b[i]=a[left];
            left++;
		}
		else
		{
            i++;
			b[i]=a[right];
            right++;
			tol = tol + mid - left + 1;
		}
	}
	while(left<=mid)
	{
        i++;
		b[i]=arr[left];
        left++;
	}
	while(right<=r)
	{
        i++;
		b[i]=arr[right];
        right++;
	}
	for(int j=1;j<=lenth;j++)
	{
        int temp = l + j - 1;
		arr[temp]=b[j];
	}

	return;
}
void sort(int arr[],int l,int r)
{
	if(l ==r )
    {
        return;
    }
	int mid=(l+r)>>1;
	sort(arr,l,mid);
	sort(arr,mid+1,r);
	merge(arr,l,mid,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,1,n);
	cout<<tol;
	return 0;
}


//进行归并排序同时计数，计入arr数组