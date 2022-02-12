#include <iostream>
#include <set>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int mp[100][100];
int n,e; 
const int inf=9999;
int from,to;
int d[100];
int sum;
bool vis[100]={false};
int pre[100];

void dij(int s)//sΪԴ��
{
	fill(d,d+100,inf); //������d���鸳ֵΪ inf
	d[s] = 0;//��㵽����ľ���Ϊ
	for(int i=0; i < n; i++)
          pre[i] = i;
     for(int i=0; i < n; i++){
		int u = -1;//u��d[u]��С��min�����С��d[u] 
		int min = inf;
		for(int j=0; j < n; j++){
			if(vis[j] == false && d[j] < min)
			{
				u = j;
				min = d[j];
			}
		}
		if(u == -1)
		  return;
		vis[u] = true;
		for(int v=0; v < n; v++){
			//���vδ����&&u�ܵ���&&��uΪ�н�������d[v]����
		 	if(vis[v] == false && mp[u][v] != inf && d[u]+mp[u][v] < d[v]){
		    	d[v] = d[u]+mp[u][v];
		    	pre[v] = u;
			}
		}
	} 
	return;
 } 
 
 
void DFS(int s,int v,int sum){
	if(v == s){
	  	cout << s;
		  return; 
	}
	sum =sum+mp[pre[v]][v];
	DFS(s,pre[v],sum);
	cout << "-->" << v;
}


int main()
{
	for(int i=0; i<100; i++)
	  for(int j=0; j<100; j++)
	    mp[i][j] = 9999;
	cin >> n >> e;
	for(int i=0; i < e/2; i++){
	  	int a,b,c;
	  	cin >> a >> b >> c;
	  	mp[a][b] = c;
	  	mp[b][a] = c;
	  }

	  cin >> from >> to;
	if(from == to){
         cout << from << "-->" << from << ":" << 0;
    return 0;
    }
	dij(from);
	DFS(from,to,sum);
	  cout << ":" << d[to];
	return 0;
 } 


 

