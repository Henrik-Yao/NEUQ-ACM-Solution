#include<bits/stdc++.h>
using namespace std;
queue<int >que;
vector<int>vec[110];
int n,m,cnt,pan,ru[110],sta[110],top=0,x,y;
void bfs(){
	while(que.size()){
		cnt++;
		if(que.size()>1)pan=1;
		int u=que.front();
		que.pop();
		for(int i=0;i<vec[u].size();i++){
			ru[vec[u][i]]--;
			if(ru[vec[u][i]]==0){
				que.push(vec[u][i]);
			}
		}
	}
}
int main(){
	while(cin>>n>>m){
		cnt=0;
		pan=0;
		for(int i=1;i<=n;i++)vec[i].clear();
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			vec[x].push_back(y);
			ru[y]++;
		}
		for(int i=1;i<=n;i++){
			//cout<<ru[i]<<' ';
			if(ru[i]==0){
				que.push(i);
			}
		}
		bfs();
		if(cnt!=n)cout<<0<<endl;
		else if(pan==1)cout<<2<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
