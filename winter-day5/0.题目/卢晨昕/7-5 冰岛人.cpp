#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
//****�˵���Ϣ 
struct peo
{
	string ming;
	string xing;
	int sex;//1Ϊ�У�2ΪŮ
	int par;//��¼�ж������� 
}p[100005];
map<string,int>id;//��������ֵ��˵ı�� 
map<string,int>idd;//����������˵ı�� 
//**************************************
//***��¼���ӹ�ϵ *******
struct node
{
	int to,nex,pre;
}e[200005];
int head[200005];
int cnt;
void add(int a,int b)
{
	e[++cnt].to=b;
	e[cnt].pre=a;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
//***********************
int v[100005];//��¼ĳ���Ƿ񱻷��ʹ� 
int flag=0;//��¼�Ƿ�Ϊ����  0����  1�� 
int d[100005];//��¼�ǵ�һ���˵ĵڼ������� 
void dfs1(int x,int step)
{
	if(flag==1)return;
	for(int i=head[x];i;i=e[i].nex)
	{
		int y=e[i].to;
		if(!v[y])
		{
			v[y]=1;
			d[y]=step;
			dfs1(y,step+1);
		}
		else
		{
			flag=1;
		}
	}
}
void dfs2(int x,int step)
{
		if(flag==1)return;
		if(step>=4)return;
		for(int i=head[x];i;i=e[i].nex)
		{
			int y=e[i].to;
			if(!v[y])
			{
				v[y]=1;
				dfs2(y,step+1);
			}
			else if(v[y]&&d[y]<4)
			{
				flag=1;
			}
		}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		p[i].ming=a;
		
		if(b[b.length()-1]=='m')
		{
			p[i].sex=1;
			p[i].xing=b.substr(0,b.length()-1);
			p[i].par=0;
		}
		else if(b[b.length()-1]=='f')
		{
			p[i].sex=2;
			p[i].xing=b.substr(0,b.length()-1);
			p[i].par=0;
		}
		else if(b[b.length()-1]=='n')
		{
			p[i].sex=1;
			p[i].xing=b.substr(0,b.length()-4);
			add(i,idd[p[i].xing]);
			p[i].par=p[idd[p[i].xing]].par+1;
		}
		else if(b[b.length()-1]=='r')
		{
			p[i].sex=2;
			p[i].xing=b.substr(0,b.length()-7);
			add(i,idd[p[i].xing]);
			p[i].par=p[idd[p[i].xing]].par+1;
		}
		id[p[i].ming+p[i].xing]=i;
		idd[p[i].ming]=i;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string ming1,xing1,ming2,xing2;
		cin>>ming1>>xing1;
		cin>>ming2>>xing2;
		int a=id[ming1+xing1],b=id[ming2+xing2];
		if(!a||!b)
		{
			cout<<"NA"<<endl;
		}
		else if(p[a].sex==p[b].sex)
		{
			cout<<"Whatever"<<endl;
		}
		else
		{
			if(p[a].par<p[b].par)swap(a,b);
			memset(v,0,sizeof(v));
			memset(d,0x3f,sizeof(d));
			flag=0;
			v[a]=1;
			d[a]=0;
			dfs1(a,1);
			
			if(!v[b])
			{
				v[b]=1;
			}
			else if(v[b]&&d[b]<4)
			{
				flag=1;
			}
			
			dfs2(b,1);
			if(flag==0)
			{
				cout<<"Yes"<<endl;
			}
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
