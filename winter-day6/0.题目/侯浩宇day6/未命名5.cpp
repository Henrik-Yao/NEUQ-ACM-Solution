#include<bits/stdc++.h>
using namespace std;
int n,N=1000;
int a[10000];
void f3(int a[],int s,int m){
 	int x=a[s];
 	for(int j=2*s;j<=m;j*=2){
  		if(j<m && a[j]<a[j+1]) j++;
  		if(x>=a[j])  break;
  		a[s]=a[j];
  		s=j;
 	}
 	a[s]=x;
}
void f2(int a[]){
 	for(int i=n/2;i>0;i--){
  		f3(a,i,n);
 	}
} 
void f1(int a[]){
 	f2(a);
 	for(int i=1;i<=n;i++)
  		cout<<a[i]<<" ";
 	cout<<endl;
 	for(int i=n;i>1;i--){
  		swap(a[1],a[i]);   
  		f3(a,1,i-1);
  		for(int i=1;i<=n;i++)
   			cout<<a[i]<<" ";
  		cout<<endl;
 	}
}
int main(){
 	cin>>n;
 	for(int i=1;i<=n;i++)
  		cin>>a[i];
 	f1(a);
 	return 0;
}
