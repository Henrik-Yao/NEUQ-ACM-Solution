#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[10001],n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int proSum=0,maxSum=0;
	for(int i=0;i<n;i++){
		if(proSum<0)
			proSum=arr[i];		
		else
			proSum=proSum+arr[i];
		if(maxSum<proSum)
			maxSum=proSum;	
	}
	cout<<maxSum<<endl;
	return 0;
}
