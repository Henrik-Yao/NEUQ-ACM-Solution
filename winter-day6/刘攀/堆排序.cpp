#include<bits/stdc++.h>
using namespace std;
int n,x;
void adjust(vector<int>&arr,int len,int index){
	int left=2*index+1;
	int right=2*index+2;
	int maxidx=index;
	if(left<len&&arr[left]>arr[maxidx]) maxidx=left;
	if(right<len&&arr[right]>arr[maxidx]) maxidx=right;
	if(maxidx!=index){
		swap(arr[maxidx],arr[index]);
		adjust(arr,len,maxidx);
	}
}
void heapsort(vector<int>&arr,int size){
	for(int i=size/2-1;i>=0;i--){
		adjust(arr,size,i);
	}
	for(int i=size-1;i>=1;i--){
		for(int j=0;j<arr.size();j++){
			cout<<arr[j]<<" ";
		}
		cout<<endl;
		swap(arr[0],arr[i]);
		adjust(arr,i,0);
	}
}
int main(){
	vector<int>v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	heapsort(v,v.size());
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
