#include<bits/stdc++.h>
using namespace std;
int n,m;
int indegree[1000];
vector<int> v[1000];//����ڽӱ� 
vector<int> ans;//���������Ľ�� 
queue<int>q;//���� 
int main(){
	while(cin>>n>>m){
	int flag=0;//�����ж��Ƿ��ж��ֽ�� 
	int cnt=0;// ��¼�ʼ�м������Ϊ0�ĵ� 
	for(int i=1;i<=m;i++){
		int d,u;
		cin>>d>>u;
		v[d].push_back(u);//����ͼ
		indegree[u]++; //��ȵĸ��� 
	}
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){//�����������ҳ��м������Ϊ0�ĵ� 
			q.push(i);
			cnt++;
		}
	}
	if(cnt>1) flag=1;
	int cou=0;
	while(!q.empty()){//��������ģ�� 
		int p=q.front();
		q.pop();
		ans.push_back(p);
		for(int i=0;i<v[p].size();i++){
			int y=v[p][i];
			indegree[y]--;
			if(!indegree[y]){
				q.push(y);//����һ�����Ϊ0��Ԫ�� 
			}
		}
	}
	if(ans.size()==n){//��������ɹ� 
		if(!flag) cout<<"1"<<endl;
		else cout<<"2"<<endl;
	}
	else cout<<"0"<<endl;//������������ 
	    for(int i = 0;i < m;i++)//��ղ��� 
        v[i].clear();
        ans.clear();
		while(!q.empty())q.pop();
		memset(indegree,0,sizeof(indegree));
    }
}
