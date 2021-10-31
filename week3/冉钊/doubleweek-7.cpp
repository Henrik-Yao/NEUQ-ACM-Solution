#include<iostream>
using namespace std;
int n;
int v[1000001],s[1000001];
long long flag=0;
void merge(int l,int mid,int r){
     int i,j,k;                 
     i=l;j=mid+1;k=l;
for(;i<=mid&&j<=r;){
        if(v[i]>v[j]){
            flag=flag+(mid-i)+1;
          s[k++]=v[j++];
        }else{
         s[k++]=v[i++];
        }
}
while(i<=mid)
s[k++]=v[i++];
while(j<=r)                                                          
s[k++]=v[j++];
    k=l;
for(i=l;i<=r;i++){
  v[i]=s[k++];
}//用有序的s覆盖无序的v，归并完成；
}
void merge_sort(int l,int r){
        if(l>=r) return;
        int  mid=l+(r-l)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,mid,r);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>v[i];
     
    merge_sort(0,n-1);

    cout<<flag;

    return 0;
}