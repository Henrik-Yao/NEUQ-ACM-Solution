#include <bits/stdc++.h>
using namespace std;
int n,c[10];
char a[10],b[10];
void pailie(int m,int n)
{
	if(m==n+1)//�����ȫ���кͷ�����һ��ݹ������ 
	{
		for(int i=0;i<=n;i++) cout<<b[i];//ע���������b���� 
		cout<<endl;
		return;
	} 
	for(int i=0;i<=n;i++)
	{
		if(c[i]==1) continue;
		b[m]=a[i];//����ʱ���洢 
		c[i]=1;
		pailie(m+1,n);
		c[i]=0;
	}
}
int main()
{
	cin>>a;
	n=strlen(a)-1;
	sort(a,a+strlen(a));
	//for(int i=0;i<=n;i++) cout<<a[i];
	pailie(0,n);
	return 0; 
}
