/*
7-6 二分查找
对于输入的n个整数，先进行升序排序，然后进行二分查找。
输入格式:
测试数据有多组，处理到文件尾。每组测试数据第一行输入一个整数n(1≤n≤100)，
第二行输入n个各不相同的待排序的整数，第三行是查询次数m（1≤m≤100），
第四行输入m个待查找的整数。
输出格式:
对于每组测试，分2行输出，第一行是排序后的升序的结果，每两个数据之间留一个空格；第二行是查找的结果，
若找到则输出排序后元素的位置（从1开始，每两个数据之间留一个空格），否则输出0。
输入样例:
9
4 7 2 1 8 5 9 3 6
5
10 9 8 7 -1
输出样例:
1 2 3 4 5 6 7 8 9
0 9 8 7 0
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int l,r,mi,n,m,a[128],b[128];
	while(cin>>n){
		for(int i=0;i<n;i++) cin>>a[i];
		cin>>m;
		for(int i=0;i<m;i++) cin>>b[i];
		sort(a,a+n);
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<endl;
		for(int i=0;i<m;i++){
			l=0,r=n-1;
			while(l<=r){
				mi=l+((r-l)/2);
				if(a[mi]>b[i]) r=mi-1;
				else if(a[mi]<b[i]) l=mi+1;
				else break;
			}
			if(l>r) cout<<"0 ";
			else cout<<mi+1<<" ";
		}
		cout<<endl;
	}
}
