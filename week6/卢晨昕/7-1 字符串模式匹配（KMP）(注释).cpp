#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int nex[1000005],f[1000005];
int ans=0;
void setup_nex(char a[])
{
	nex[0]=0;
	//j��ʾ��һ�ε�ƥ���˼��� 
	for(int i=1,j=0;i<strlen(a);i++)
	{
		//������С���ȣ�ֱ���п���ƥ���ϵĳ��� 
		while(j&&a[i]!=a[j])j=nex[j-1];//a[j]����һ��ƥ��ɹ���ǰ׺����һ��  a[i]����һ��ƥ��ɹ�����һ�� 
		//�����һ��û��ƥ��ɹ�������ε�һ�����ƥ��һ�� 
		if(a[i]==a[j])j++;
		nex[i]=j;
	}
}
void setup_f(char a[],char b[])//��   �� 
{
	int len1=strlen(a);
	int len2=strlen(b);
	for(int i=0,j=0;i<len1;i++)
	{
		while(j&&a[i]!=b[j])j=nex[j-1];
		if(a[i]==b[j])j++;
		f[i]=j;
		if(j==len2)ans++;
	}
}
int main()
{
	char t[1000005],p[1000005];
	cin>>t>>p;//��   �� 
	setup_nex(p);
	setup_f(t,p);
	cout<<ans;
	return 0;
}
