/*
7-1 直接插入排序
给定一个整数序列，请按非递减序输出采用直接插入排序的各趟排序后的结果。
输入格式:
测试数据有多组，处理到文件尾。每组测试数据第一行输入一个整数n（1≤n≤100），第二行输入n个整数。
输出格式:
对于每组测试，输出若干行，每行是一趟排序后的结果，每行的每两个数据之间留一个空格。
输入样例:
4
8 7 2 1
输出样例:
7 8 2 1
2 7 8 1
1 2 7 8
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[128];
	while(cin>>n){
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			int temp=a[i];
			int j=i-1;
			while(j>=0 && a[j]>temp){
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=temp;
			for(int j=0;j<n;j++) cout<<a[j]<<' ';
			cout<<endl;
		}
	}
}
