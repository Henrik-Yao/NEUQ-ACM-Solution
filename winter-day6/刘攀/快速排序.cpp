#include<bits/stdc++.h>
using namespace std;
int n;
void print(int *arr){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	cout<<endl;
}
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void quicksort(int *arr,int left,int right){
	if(left>=right){
		return;
	}
	int l=left;
	int r=right;
	int temp=arr[left];
	while(l<r){
		while(l<r&&arr[r]>temp){
			r--;
		}
		while(l<r&&arr[l]<=temp){
			l++;
		}
		swap(arr[r],arr[l]);
	}
	//将起始值和ij相等的交换，此时左边数都小，右边数都大 
	swap(arr[l],arr[left]);
	print(arr);
	quicksort(arr,left,l-1);
	quicksort(arr,l+1,right);
}
int main(){
	cin>>n;
	int arr[n]; 
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
