#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000001];
long long ans=0;
void hebing(int begin,int mid,int end){
 int left_index=begin;
 int right_index=mid+1;
 for(int i=begin;i<=end;i++){
 	if((right_index>end)||(left_index<=mid&&a[left_index]<=a[right_index]))b[i]=a[left_index++];
 
 else{
 	b[i]=a[right_index++];
 	ans=ans+ mid-left_index+1;
 }
}
 for(int i=begin;i<=end;i++){
 	a[i]=b[i];
 }
}
void merge_sort(int begin,int end){
	int mid=(begin+end)/2;
	if(begin==end)return;
	else{
		merge_sort(begin,mid);
		merge_sort(mid+1,end);
		hebing(begin,mid,end);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	merge_sort(1,n);
    cout<<ans;
	return 0;
}

