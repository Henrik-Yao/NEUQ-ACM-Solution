#include <bits/stdc++.h>
using namespace std;
int mark[200005][2];//[0]Ϊ��[1]Ϊĸ 
bool visit[200005];
char sex[200005];
bool judge;//��¼�����Ƿ�����ͬ���� 
int num,k;
void search(int remp,int flag)//flag��¼���������� 
{
	if(flag>5)
	return;
	if(remp<=0)
	return;
	if(visit[remp])
	judge=1;//����ǰ��ǹ������ǹǿ� 
	visit[remp]=1;//�����ѱ�� 
	search(mark[remp][0],flag+1);
	search(mark[remp][1],flag+1);
	
}

int main()
{
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		int remp,remp1,remp2;
		char ch;
		cin>>remp>>ch>>remp1>>remp2;
		sex[remp]=ch,sex[remp1]='M',sex[remp2]='F';//������ı��˺͸�ĸ�Ա���� 
		mark[remp][0]=remp1;mark[remp][1]=remp2;//������ӹ�ϵ 
	}	
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int remp1,remp2;
		cin>>remp1>>remp2;
		if(sex[remp1]==sex[remp2])
		{
			cout<<"Never Mind"<<endl;
			continue;
		}
		memset(visit,0,sizeof(visit));
		judge=0;
		search(remp1,1);
		search(remp2,1);
		if(judge)
		cout<<"No";
		else
		cout<<"Yes";
		if(i!=k)
		cout<<endl;
	}
}
