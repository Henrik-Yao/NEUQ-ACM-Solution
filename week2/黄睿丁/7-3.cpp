#include <iostream>
using namespace std;
void gui(int a[],int s,int e,int m);
void bin(int a[],int s,int e,int m);
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	cin>>a[i];
	gui(a,1,n,(n+1)/2);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
}

void gui(int a[],int s,int e,int m)
{
	if(s==e)
	return;
	gui(a,s,m,(s+m)/2);
	gui(a,m+1,e,(m+1+e)/2);
	bin(a,s,e,m);
}

void bin(int a[],int s,int e,int m)
{
	int b[e-s+1];
	int i=s,j=m+1,l=0;
	while(i<=m&&j<=e)
	{
		if(a[i]>a[j])
		b[l++]=a[j++];
		else
		b[l++]=a[i++];
	}
	while(i<=m)
	b[l++]=a[i++];
	while(j<=e)
	b[l++]=a[j++];
	for(i=0;i<e-s+1;i++)
	a[s+i]=b[i];
}
