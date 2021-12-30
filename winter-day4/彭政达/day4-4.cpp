/*
7-4 ���·��֮Floyd
����д����ʵ���������������·����Floyd�㷨����ص���ܹ��ǵ�����������¥�ȵȣ�
����򻯳ɱ�ţ�Ҫ���ܹ���ѯ���������㣨�ñ�ű�ʾ��������·������С���롣
˵����1������������޲�����100��2������Ȩֵ���޲�����9998��
��������:
��һ�У�����������vN��eN��ͼ�ж������ͺͱ������� ��������vN���ߵ���Ϣ��
��㣬�յ㣬Ȩֵ��������һ�У��Կո�ָ����� ��������Ǵ���ѯ������������յ�ı��
��ÿ��һ����ѯ��������յ��ż�Ҳ�ǿո�ָ�����
6 8
0 5 100
0 2 10
0 4 30
1 2 5
2 3 50
3 5 10
4 3 20
4 5 60
0 5
2 0
��������Ϣ���������ͱ������ߵ���Ϣ��������Ҫ��ѯ�Ķ�����Ϣ�� 
�������:
��������У�ǰ���зֱ���������ѯ�Ľ����������㵽�յ��·��˵�������Ǿ��룬
�м���ð�ŷָ������������䲻�ɴ�������-1�����һ���������ɴ�����������������
(���ж��飬����λ����ǰ��һ�飬ע�⣺���������ɵ���������)��
0->4->3->5:60
2->0:-1
1->2->3->5:65
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,z,posx=-1,posy=-1,massimo;
int g[128][128],path[128][128];
int pre[128];
void effect(int x,int y){
	int k=path[x][y];
	if(k==-1){
		pre[y]=x;
		return;
	}
	effect(k,y);
	effect(x,k);
}
void print(int x,int y){
	if(x==y){
		cout<<x;
		return;
	}
	print(x,pre[y]);
	cout<<"->"<<y;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("in4.txt","r",stdin);
	memset(path,-1,sizeof(path));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		g[i][i]=0;
		for(int j=i+1;j<n;j++)
			g[i][j]=g[j][i]=32767;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(g[x][y]>z) g[x][y]=z;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				if(g[j][k]>g[j][i]+g[i][k]){
					g[j][k]=g[j][i]+g[i][k];
					path[j][k]=i;
				}
	for(int i=0;i<2;i++){
		cin>>x>>y;
		if(x==y) cout<<x<<"->"<<y<<":0"<<endl;
		else{
			if(g[x][y]==32767) cout<<x<<"->"<<y<<":-1"<<endl;
			else{
				memset(pre,0,sizeof(pre));
				effect(x,y);
				print(x,y);
				cout<<":"<<g[x][y]<<endl;
			}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(mp[i][j]!=32767 && g[i][j]>massimo){
				massimo=g[i][j];
				posx=i;
				posy=j;
			}
	memset(pre,0,sizeof(pre));
	if(posx!=-1 && posy!=-1){
		effect(posx,posy);
		print(posx,posy);
		cout<<":"<<g[posx][posy];
	}
}
