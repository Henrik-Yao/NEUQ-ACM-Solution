#include<bits/stdc++.h>
using namespace std;
struct ax{
	char name[4];
	int t,p;
}a[10005];
bool vis[10005];
int f[10005],ans[10005];//f[i]��ʾ���Ϊi��������Ȧ�ӣ�ans��¼���� 
int n,m,l,num,ptime,c;//ptimeΪ��ʾ��һ�������ʱ��ǰ��ʱ�䣬cͳ��������ǰ���� 
char name[4];
double w;
map<string,int> mp;//��������������� 
int main()
{
	cin>>n>>m;
	while(m--)
	{
		cin>>l;
		for(int i=0;i<l;i++){
			cin>>name;
			f[mp[name]=++num]=m+1;//��¼Ȧ�� 
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i].name>>a[i].t>>a[i].p;
		if(a[i].p>60)a[i].p=60;//t>60��60�� 
	}
	int i=0;
	while(i<n)
	{
		while(i<n && vis[i])i++;//�Ź��������� 
		int d=f[mp[a[i].name]],j=i;//dΪȦ�ӣ�j��ö�ٺ������ 
		if(i>=n)break;//�������� 
		do{
			if(vis[j] || f[mp[a[j].name]]!=d){//��û�Ź���������Ȧ�ӵ� 
				j++;
				continue;
			}
			w+=max(0,ptime-a[j].t);//w��¼�ȴ�ʱ�䣬����ǰʱ���뵽��ʱ���ֵ��<0��ֵΪ0�� 
			ans[c++]=j;//ͳ�ƴ� 
			ptime=max(ptime,a[j].t)+a[j].p;//����ʱ�� 
			vis[j++]=1;//������ 
		}
		while(d && j<n && a[j].t<=ptime);//������Ȧ�Ӳ��Һ�����˵ĵ���ʱ��ȵ�ǰʱ��С 
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[ans[i]].name<<endl;
	}
	printf("%.1f",w/n);
	return 0;
}
