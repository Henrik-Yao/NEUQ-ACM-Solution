#include<bits/stdc++.h>
using namespace std;
int n;
void print(int *arr){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	cout<<endl;
}
void quicksort(int *arr,int left,int right){
	if(left>=right){
		return;
	}
	int l=left;
	int r=right;
	int key=arr[left];
	while(l<r){
		while(l<r&&arr[r]>key){
			r--;
		}
		while(l<r&&arr[l]<=key){
			l++;
		}
		swap(arr[r],arr[l]);
	}
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
