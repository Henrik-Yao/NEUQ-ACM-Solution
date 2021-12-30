/*
7-6 快速排序
给定包含n个元素的整型数组a[1],a[2],...,a[n]，利用快速排序算法对其进行递增排序，
请输出排序过程，即每次Partition之后的数组。每次选择所处理的子数组的第一个元素作为基准元素。
输入格式:
输入为两行，第一行为一个整数n（1<n≤1000），表示数组长度。第二行为n个空格间隔的整数，表示待排序的数组。
输出格式:
输出为若干行，每行依次输出Partition后的数组，每个元素后一个空格。
输入样例:
5
4 5 3 2 1
输出样例:
2 1 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
*/
#include <bits/stdc++.h>
using namespace std;
void quicksort(int *a,int left,int right,int n){
	if(left>=right) return;
	int l=left,r=right,key=a[l];
	while(l<r){
		while(l<r && a[r]>key) r--;
		while(l<r && a[l]<=key) l++;
		int temp=a[r];a[r]=a[l];a[l]=temp;
	}
	int temp=a[l];a[l]=a[left];a[left]=temp;
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
	quicksort(a,left,l-1,n);
	quicksort(a,l+1,right,n);
}
int main(){
	int n,a[n];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	quicksort(a,0,n-1,n);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
