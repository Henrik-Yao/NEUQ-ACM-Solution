/*
7-3 ����������
����һ������Ϊn(1<=n<=15)���������� nums ��0<=nums[i]<=100��
�ҳ�����ӡ���и������в�ͬ�ĵ��������еĸ���sum������������������������Ԫ�� ��
���������������ȣ�Ҳ���������������е�һ��������������磺
n=4,nums = [4,6,7,7]
�������������У�[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]
sum=8
�����ʽ:
��һ���и���n
�ڶ���ΪnumsԪ�أ��ո����
�����ʽ:
һ������sum
��������:
���������һ�����롣���磺
4
4 6 7 7
�������:
�����������Ӧ����������磺
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
