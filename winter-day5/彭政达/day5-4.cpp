/*
7-4 二分查找
输入n值(1<=n<=1000)、n个非降序排列的整数以及要查找的数x，使用二分查找算法查找x，
输出x所在的下标（0~n-1）及比较次数。若x不存在，输出-1和比较次数。
输入格式:
输入共三行： 第一行是n值； 第二行是n个整数； 第三行是x值。
输出格式:
输出x所在的下标（0~n-1）及比较次数。若x不存在，输出-1和比较次数。
输入样例:
4
1 2 3 4
1
输出样例:
0
2
*/
#include<iostream>
using namespace std;
int main(){
	int l,r,m,count=0,n,x,a[1005];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>x;
	l=0,r=n-1;
	while(l<=r){
		count++;
		m=l+((r-l)/2);
		if(a[m]>x) r=m-1;
		else if(a[m]<x) l=m+1;
		else break;
	}
	if(l>r) cout<<"-1";
	else cout<<m;
	cout<<endl<<count;
}
