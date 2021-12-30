/*
7-6 ��������
��������n��Ԫ�ص���������a[1],a[2],...,a[n]�����ÿ��������㷨������е�������
�����������̣���ÿ��Partition֮������顣ÿ��ѡ���������������ĵ�һ��Ԫ����Ϊ��׼Ԫ�ء�
�����ʽ:
����Ϊ���У���һ��Ϊһ������n��1<n��1000������ʾ���鳤�ȡ��ڶ���Ϊn���ո�������������ʾ����������顣
�����ʽ:
���Ϊ�����У�ÿ���������Partition������飬ÿ��Ԫ�غ�һ���ո�
��������:
5
4 5 3 2 1
�������:
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
