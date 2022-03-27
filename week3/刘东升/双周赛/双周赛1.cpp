#include<bits/stdc++.h> 
using namespace std;
int find(int m,int q);//定义一个查找函数 
const int C=10001;
int a[C]; 
int main()
{
	int n,i,j=0;cin>>n;//j来判断是否全为负数 
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>0)
		{
			j=1;
		}
	}
	if(j==1)
	{
		cout<<find(1,n);
	}
	else
	{
		cout<<0;
	}
}
int find(int m,int q)
{
	if(m==q)
	{
		return a[m];//当分治到最小的时候直接输出 
	}
	int middle=(m+q)/2;
 	int M=find(m,middle),Q=find(middle+1,q);//去找各自的最大归并下去 
	int Msum=0,Nsum=0,mm=-1e9,qq=-1e9;
 	for(int i=middle;i>=m;i--)//从中间往前找 
	{
  		Msum+= a[i];
  		mm=max(mm,Msum);
 	}
 	for(int i=middle+1;i<=q;i++)//从中间往后找 
	{
  		Nsum+= a[i];
  		qq=max(qq,Nsum);
 	}
 	return max(max(M,Q),max(mm+max(0,qq),max(0,mm)+qq));//寻找最大 
}
