/*
7-3 递增子序列
给你一个长度为n(1<=n<=15)的整数数组 nums ，0<=nums[i]<=100。
找出并打印所有该数组中不同的递增子序列的个数sum，递增子序列中至少有两个元素 。
如出现两个整数相等，也可以视作递增序列的一种特殊情况。例如：
n=4,nums = [4,6,7,7]
满足条件的序列：[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]
sum=8
输入格式:
第一行中给出n
第二行为nums元素，空格隔开
输出格式:
一个整数sum
输入样例:
在这里给出一组输入。例如：
4
4 6 7 7
输出样例:
在这里给出相应的输出。例如：
8
*/
#include<bits/stdc++.h>
using namespace std;
int a[20],sum=0,n;
map<string,int> m;
string str;
string tra(int x){
	ans.clear();
	while(x){
		int t=x%10;
		x/=10;
		str=(char)(t+48)+str;
	}
}
void dfs(int t,string s){
	for(int i=t+1;i<=n;i++)
		if(a[i]>=a[t]){
			string st=s+tra(a[i]+200);
			if(!m[st]){
				m[st]=1;
				sum++;
			}
			dfs(i,st);
		}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		tra(a[i]+200)
		dfs(i,str);
	}
	cout<<sum;
}
