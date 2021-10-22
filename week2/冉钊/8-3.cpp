#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int merge(int c[],int s[],int left,int mid,int right){
	int i,j,k;
	i=left;
	j=mid+1;
	k=left;//s的初始位置 
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
		}//比较，存入s中，直到某一半存完了 
		
	}
	while(i<=mid){
		s[k++]=c[i++];
	} 
	while(j<=right){
		s[k++]=c[j++];
	}
	
	
	return 0;
}//默认左半 右半边已经排序的最初排序式子 ,s即为排序成功后的数列 
int merge_sort(int a[],int b[],int left,int right){
	int c[n];
	if(left==right){
		b[left]=a[right];
	}
	else{
	
	int mid=(left+right)/2;
	merge_sort(a,c,left,mid);
	merge_sort(a,c,mid+1,right);
	//递归划分出最小的一个个元素 ,当深处出现left=0，right=1时，就递归到了终点 ，出现了只有两个元素的数组 
	merge(c,b,left,mid,right);//局部归并处理 
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
