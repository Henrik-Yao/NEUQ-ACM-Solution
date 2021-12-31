#include<iostream>
using namespace std;

int n;

void swap(int a[],int x,int y)
{
    int temp;
    temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void quicksort(int a[],int front,int end)
{
	if(front >= end)
    {
        return ;
    }
	int i = front;
    int j = end;
	int key = a[i];
	int temp;
	while(i != j)
	{
		while(i<j && a[j] > key)
        {
            j--;
        }
		while(i<j && a[i] <= key)
        {
            i++;
        }
		if(i < j)
        {
            swap(a,i,j);
        }
	}

	swap(a,front,i);

    int flag = 1;
	for(int k=0;k<n;k++)
    {
        cout<<a[k]<<" ";
        if(k!=0 && a[k-1] > a[k])
        {
            flag = 0;
        }
    }
	cout<<endl;
    if(flag)
    {
        return ;
    }
	quicksort(a,front,j-1);
	quicksort(a,i+1,end);
	
}
int main()
{
	
	int a[10000];
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
	quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
	return 0;
}