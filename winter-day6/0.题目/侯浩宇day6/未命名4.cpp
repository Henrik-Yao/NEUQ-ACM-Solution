#include <bits/stdc++.h>
using namespace std;
long int ans=0,a[500001],b[500001];
void msort(int l,int r){
    if(l==r) return;
    int mid=(l+r)/2;
    msort(l,mid);
    msort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            b[k]=a[i];k++;i++;
        }
		else{
            b[k]=a[j];k++;j++;
            ans+=mid-i+1;
        }
    }
 
    while(i<=mid){
        b[k]=a[i];k++;i++;
    }
    while(j<=r){
        b[k]=a[j];k++;j++;
    }
    for(int i=l;i<=r;i++) a[i]=b[i];
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    msort(1,n);
    cout<<ans;
}
