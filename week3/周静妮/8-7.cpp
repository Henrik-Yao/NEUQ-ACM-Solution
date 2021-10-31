#include <bits/stdc++.h>
using namespace std;
int a[1000001],b[1000001],c[1000001];
long long count=0;
void merge(int l,int r){
    int mid=(l+r)/2;
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]){
            b[k]=a[i];
            k++;i++;
        }
        else {
        	::count+=mid-i+1;
            b[k]=a[j];
            k++;j++;
        }
    }
    while(i<=mid){
    	b[k++]=a[i++];
	}
	while(j<=r){
		b[k++]=a[j++];
	}
	for(i=l;i<=r;i++){
		a[i]=b[i];
	}
}
void mergesort(int arr[],int l,int r){
    if(l==r) return;
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(l,r);
    return;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    mergesort(a,1,n);
    cout<<::count<<endl;
}
