/*
7-5 堆排序
对n个数，要求用堆排序（最大堆）对其进行排序。
输入格式:
第一行一个n（n<1000）。第二行给出n个数。
输出格式:
输出n行，每行n个数。第一行表示将n个数(将n个数看成一棵树)变成最大堆后的结果，
第二行表示将上次结果的根节点交换到现有节点的最后一个节点
（然后将除最后一个节点的数看成一颗树），然后将该剩余节点树从新变成最大堆后的结果输出
（包括交换到最后的节点），依次类推。
输入样例:
6
7 1 6 4 3 5
输出样例:
7 4 6 1 3 5 
6 4 5 1 3 7 
5 4 3 1 6 7 
4 1 3 5 6 7 
3 1 4 5 6 7 
1 3 4 5 6 7 
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[1005];
void adjust(int a[],int s,int m){
 	int x=a[s];
 	for(int j=s*2;j<=m;j*=2){
  		if(j<m && a[j]<a[j+1]) j++;
  		if(x>=a[j]) break;
  		a[s]=a[j];
  		s=j;
 	}
 	a[s]=x;
} 
int main(){
 	cin>>n;
 	for(int i=1;i<=n;i++) cin>>a[i];
 	for(int i=n/2;i>0;i--) adjust(a,i,n);
 	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
 	cout<<endl;
 	for(int i=n;i>1;i--){
  		swap(a[1],a[i]);   
  		adjust(a,1,i-1);
  		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
  		cout<<endl;
 	}
}

