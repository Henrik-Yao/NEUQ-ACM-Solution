/*
7-5 ������
��n������Ҫ���ö��������ѣ������������
�����ʽ:
��һ��һ��n��n<1000�����ڶ��и���n������
�����ʽ:
���n�У�ÿ��n��������һ�б�ʾ��n����(��n��������һ����)������Ѻ�Ľ����
�ڶ��б�ʾ���ϴν���ĸ��ڵ㽻�������нڵ�����һ���ڵ�
��Ȼ�󽫳����һ���ڵ��������һ��������Ȼ�󽫸�ʣ��ڵ������±�����Ѻ�Ľ�����
���������������Ľڵ㣩���������ơ�
��������:
6
7 1 6 4 3 5
�������:
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

