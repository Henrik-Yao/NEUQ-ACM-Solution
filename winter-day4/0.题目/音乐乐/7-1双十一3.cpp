#include<bits/stdc++.h> 
#define Inf 0x3f3f3f3f
using namespace std;
int m[105][105];
int vis[105],dis[105],total[105];
int n,e,i;
void Dijkstra(int u)
{
	memset(vis,0,sizeof(vis));
	for(int t=0;t<n;t++)
		dis[t]=m[u][t];//�Ƚ������㵽����������ֱ�Ӿ���洢�����������ļ�Ӿ�����Ƚ�
	vis[u]=1;//�����㲻�ɷ���
	for(int t=0;t<n;t++)//�����ҵ������㵽������֮�����̾���
	{
		int minn=Inf,temp=start;
		for(int i=0;i<n;i++)
		{
			if(!vis[i]&&dis[i]<minn&&t!=i)//�õ���Ŀǰ�������ľ�����̵ģ���δ�����ʹ����Ҳ�������
			{
				minn=dis[i];
				temp=i;
			}
		}
		vis[temp]=1;//tempΪ�ҵ��ľ���Ŀǰ����λ����̵ĵ㣬����Ѿ������ʹ�
		for(int i=0;i<n;i++)
		{
			if(m[temp][i]+dis[temp]<dis[i])//����ӳ����㵽temp����λ�ü���temp��������i������λ�ñȳ����㵽i�ľ���̣��͸��³����㵽i�����̾���
			{
				dis[i]=m[temp][i]+dis[temp];
			}
		}
	}
	
}
int main()
{
	while(~scanf("%d%d",&n,&e))
	{
        memset(total,0,sizeof(total));
		for(i=0;i<105;i++) 
			for(int j=0;j<105;j++)
		m[i][j]=Inf;//��ʼ����������ͼ�ϵĵ�֮��ľ����ȱ��Ϊ�����
		for(i=0;i<n;i++)
			m[i][i]=0;//һ���㵽����ľ���Ϊ0
		for(i=0;i<e;i++)
		{
			int city1,city2;
			cin>>city1>>city2>>m[city1][city2];
            m[city2][city1]=m[city1][city2];//����ͼ�����ڽӾ�������Ҫ�������
		}
		for(i=0;i<n;i++)
		{
			Dijkstra(i);
            for(int j=0;j<n;j++)
                total[i]+=dis[j];//total������㵽��������ľ���֮��
		}
		int minn=total[0],index=0;
		for(i=1;i<n;i++)
		{
			//cout<<i<<':'<<total[i]<<endl;
			if(total[i]<minn)
            {
                minn=total[i];
			    index=i;
            }
		}//�ҳ������������֮����̵ĳ�������±�
		cout<<index<<endl;
	}
	return 0;
}
