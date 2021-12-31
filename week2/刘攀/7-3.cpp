#include<bits/stdc++.h>
using namespace std;
int a[100001],c[100001];
void f(int a[],int l,int r){
	if(l>=r) return;
	int b=(l+r)/2;
	f(a,l,b);
	f(a,b+1,r);
	int k=0,i=l,j=b+1;
	while(i<=b && j<=r){
		if(a[i]<=a[j]) c[k++]=a[i++];
		else c[k++]=a[j++];		 
	}
	while(i<=b) c[k++]=a[i++];
	while(j<=r) c[k++]=a[j++]; 
	for(i=l,j=0;i<=r;i++,j++) a[i]=c[j];
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	f(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
} 

