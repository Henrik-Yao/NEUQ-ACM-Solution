#include <iostream>
using namespace std;
int a[100001],t[100001];
void sort(int f,int b)
{
	if(f==b) return;
	int m;
	m=(f+b)/2;
	sort(f,m);
	sort(m+1,b);
	int i,j,w;
	i=f;j=m+1;w=0;
	//for(int p=0;p<=1e5;p++) t[p]=0;
	while(i<=m&&j<=b)
	{
		if(a[i]>a[j])
		{
			t[++w]=a[j];
			//w++;
			j++;
		}
		else
		{
			t[++w]=a[i];
			//w++;
			i++;
		}
	}
	while(i<=m)
	{
		t[++w]=a[i];
		//w++;
		i++;
	}
	while(j<=b)
	{
		t[++w]=a[j];
		//w++;
		j++;
	}
	for(int p=f;p<=b;p++)
	{
		a[p]=t[p-f+1];
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(1,n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
