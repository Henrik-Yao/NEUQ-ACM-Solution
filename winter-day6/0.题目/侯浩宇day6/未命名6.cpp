#include<bits/stdc++.h>
using namespace std;
int n,a[1001],b[1001];
void f(int l,int r){
	if(l<r){
	int t=a[(l+r)/2];
	int m=l,p=l;
	b[l]=t;
	for(int i=l;i<=r;i++){
	if(a[i]<t){
		for(int j=r;j>p;j--)
		b[j]=b[j-1];
		b[p]=a[i];
        p++;m++;
	}
	if(a[i]>t){m++;b[m]=a[i];}
}
	for(int j=0;j<n;j++){
        a[j]=b[j];
        cout<<b[j]<<" "; 
    }
	cout<<endl;
	f(l,p-1);
	f(p+1,r);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i],b[i]=a[i];
	f(0,n-1);
	return 0;
}
