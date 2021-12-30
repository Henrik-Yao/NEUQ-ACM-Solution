#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n;
int a[maxn]={};
void adjust(int a[],int s,int m);
void heapsort(int a[],int n)
{
	for(int i=n/2;i>=1;i--) adjust(a,i,n);
	for (int i = 1; i <= n; i++) cout<<a[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n-1;i++){
		swap(a[1],a[n+1-i]);
		adjust(a,1,n-i);
		for(int j=1;j<=n;j++) cout<<a[j]<<" ";
		cout<<endl;
	}
}

int main()
{   cin >> n;
	for (int i = 1; i <=n; i++) cin>>a[i]; 
	heapsort(a,n);
	return 0;
} 
void adjust(int a[],int s,int m)
{
	int t=a[s];
	for(int j=2*s;j<=m;j*=2){
		if(j<m&&a[j]<a[j+1]) j++;
		if(t>=a[j]) break;
		a[s]=a[j];
		s=j;
	}
	a[s]=t;
}
