#include<bits/stdc++.h>  
using namespace std;
const int maxn=1e5+10;
void merge(int *a,int l,int r){
	if(l==r) return;
	else if(l==r-1){
		int temp;
		if(a[l]>a[r]) temp=a[l],a[l]=a[r],a[r]=temp;
		return ;
	}
	else{
	    int mid=(l+r)/2;
	    merge(a,l,mid);
	    merge(a,mid+1,r);	
		int p=l,q=mid+1,b[maxn];
		for(int i=l;i<=r;i++) b[i]=a[i];
		for(int i=l;i<=r;i++){
		    if(p>mid){
				b[i]=a[q];
				q++;
			}
			else if(q>r){
				b[i]=a[p];
				p++;
			}
			else if(a[p]>a[q]){
				b[i]=a[q];
				q++;
			}			
			else{
				b[i]=a[p];
				p++;
			}
		}
		for(int i=l;i<=r;i++) a[i]=b[i];
	}
}
int main(){
	int n,a[maxn];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	merge(a,0,n-1);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
