#include<bits/stdc++.h> 
using namespace std;
int find(int m,int q);//����һ�����Һ��� 
const int C=10001;
int a[C]; 
int main()
{
	int n,i,j=0;cin>>n;//j���ж��Ƿ�ȫΪ���� 
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
		return a[m];//�����ε���С��ʱ��ֱ����� 
	}
	int middle=(m+q)/2;
 	int M=find(m,middle),Q=find(middle+1,q);//ȥ�Ҹ��Ե����鲢��ȥ 
	int Msum=0,Nsum=0,mm=-1e9,qq=-1e9;
 	for(int i=middle;i>=m;i--)//���м���ǰ�� 
	{
  		Msum+= a[i];
  		mm=max(mm,Msum);
 	}
 	for(int i=middle+1;i<=q;i++)//���м������� 
	{
  		Nsum+= a[i];
  		qq=max(qq,Nsum);
 	}
 	return max(max(M,Q),max(mm+max(0,qq),max(0,mm)+qq));//Ѱ����� 
}
