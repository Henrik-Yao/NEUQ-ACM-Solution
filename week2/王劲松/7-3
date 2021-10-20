#include<bits/stdc++.h>
using namespace std;
void mergesort(int a[],int l,int r);
void merge(int a[],int mid,int l,int r);
int main(){
	int m,i;
	cin>>m;
    int a[m];
    for(i=0;i<m;i++){
        cin>>a[i];
    }
	mergesort(a,1,m);
	for(i=0;i<m;i++){
		cout<<a[i]<<' ';
        
	}
	return 0;
}
void mergesort(int a[],int l,int r){
	if(l>=r)return;
	int mid =l+(r-l)/2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,r);
	merge(a,mid,l,r);
	//return;
}
void merge(int a[],int mid,int l,int r){
	int i=l,j=mid+1,k=0;
	int *p=new int[r-l+1];
	while(i<=mid&&j<=r){
		if(a[i-1]<=a[j-1]){
			p[k++]=a[i-1];
			i++;
		}
		else p[k++]=a[j-1],j++;
	}
	while(i<=mid){
		p[k++]=a[i-1],i++;
	}
	while(j<=r){
		p[k++]=a[j-1],j++;
	}
	for(i=l,k=0;i<=r;i++,k++){
		a[i-1]=p[k];
	}
	delete []p;
}
