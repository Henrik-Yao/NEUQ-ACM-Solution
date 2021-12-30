#include<bits/stdc++.h>
#define R register
#define ll long long
using namespace std;
int n;
int a[1005];
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;ch=getchar(); 
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48),ch=getchar();
	}
	return x*f;

}
void adjust(int len,int index)
{
	int le=2*index+1;
	int ri=le+1;
	int maxidx=index;
	if(le<len && a[le]>a[maxidx])maxidx=le;
	if(ri<len && a[ri]>a[maxidx])maxidx=ri;
	if(maxidx!=index)
	{
		swap(a[maxidx],a[index]);
		adjust(len,maxidx);
	}
}
void heapsort(int size)
{
	for(int i=size/2-1;i>=0;i--)
	{
		adjust(size,i);
	}
	for(int j=0;j<n;j++)
		cout<<a[j]<<" ";
		cout<<endl;
	for(int i=size-1;i>=1;i--)
	{
		swap(a[0],a[i]);
		adjust(i,0);
		for(int j=0;j<n;j++)
		cout<<a[j]<<" ";
		cout<<endl;
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	heapsort(n);
}
