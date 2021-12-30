
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


