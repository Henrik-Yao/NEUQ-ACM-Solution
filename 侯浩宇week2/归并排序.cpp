#include<bits/stdc++.h>
using namespace std;
int n;
int merge(int c[],int s[],int left,int mid,int right){
	int i,j,k;
	i=left;
	j=mid+1;
	k=left;
	while((i<=mid)&&(j<=right)){
		if(c[i]<=c[j]){
			s[k]=c[i];
			k++;
			i++;		
		}
		else{	
			s[k]=c[j];
			k++;
			j++;
		}
	}
	while(i<=mid){
		s[k++]=c[i++];
	} 
	while(j<=right){
		s[k++]=c[j++];
	}	
	return 0;
}
int merge_sort(int a[],int b[],int left,int right){
	int c[n];
	if(left==right){
		b[left]=a[right];
	}
	else{
	int mid=(left+right)/2;
	merge_sort(a,c,left,mid);
	merge_sort(a,c,mid+1,right);
	merge(c,b,left,mid,right);
}
     return 0;
}
int main(){
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	merge_sort(a,b,0,n-1);
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
