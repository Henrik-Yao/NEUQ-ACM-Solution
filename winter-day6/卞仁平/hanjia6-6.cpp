#include<bits/stdc++.h>
using namespace std;
int n;
void swap(int a[],int index1,int index2)
{
    int t;
    t=a[index1];a[index1]=a[index2];a[index2]=t;
}
void quicksort(int a[],int be,int e)//be:begin e:end
{
	if(be>=e)return ;
	int i=be,j=e;
	int key=a[i];
	int temp;
	while(i!=j)
	{
		while(i<j&&a[j]>key)j--;
		while(i<j&&a[i]<=key)i++;
		if(i<j)   swap(a,i,j);
	} 
	swap(a,be,i);
    int flag=1;
	for(int k=0;k<n;k++)
    {
        cout<<a[k]<<" ";
        if(k!=0&&a[k-1]>a[k])flag=0;
    }
	cout<<endl;
    if(flag)return ;
	quicksort(a,be,j-1);
	quicksort(a,i+1,e);
	
}
int main()
{
	
	int a[1001];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	quicksort(a,0,n-1);
	for(int k=0;k<n;k++)cout<<a[k]<<" ";
	return 0;
}