#include<bits/stdc++.h>
using namespace std;
int n,m;
int indegree[1000];
vector<int> v[1000];//造出邻接表 
vector<int> ans;//拓扑排序后的结果 
queue<int>q;//队列 
int main(){
	while(cin>>n>>m){
	int flag=0;//用来判断是否有多种结果 
	int cnt=0;// 记录最开始有几个入度为0的点 
	for(int i=1;i<=m;i++){
		int d,u;
		cin>>d>>u;
		v[d].push_back(u);//构造图
		indegree[u]++; //入度的个数 
	}
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){//拓扑排序，先找出有几个入度为0的点 
			q.push(i);
			cnt++;
		}
	}
	if(cnt>1) flag=1;
	int cou=0;
	while(!q.empty()){//拓扑排序模板 
		int p=q.front();
		q.pop();
		ans.push_back(p);
		for(int i=0;i<v[p].size();i++){
			int y=v[p][i];
			indegree[y]--;
			if(!indegree[y]){
				q.push(y);//找下一个入度为0的元素 
			}
		}
	}
	if(ans.size()==n){//拓扑排序成功 
		if(!flag) cout<<"1"<<endl;
		else cout<<"2"<<endl;
	}
	else cout<<"0"<<endl;//不能拓扑排序 
	    for(int i = 0;i < m;i++)//清空操作 
        v[i].clear();
        ans.clear();
		while(!q.empty())q.pop();
		memset(indegree,0,sizeof(indegree));
    }
}
