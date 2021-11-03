#include <bits/stdc++.h>
using namespace std;
int path[501],v[501];
vector<int> vec[501];
queue<int> que;
int main(){
	int n,m;
	cin>>n>>m;
    while(m--){
    	int x,y;
    	cin>>x>>y;
    	vec[x].push_back(y);
	}
	int a,b,flag=0;
	cin>>a>>b;  
    que.push(a);
	v[a]=1;
	path[a]=1;
    while(que.size()){
        int t=que.front();
		que.pop();
		v[t]=0;
        if(t==b) continue;
        for(int i=0;i<vec[t].size();i++){
            int to=vec[t][i];
            path[to]+=path[t];
            if(!v[to]) que.push(to),v[to]=1;
        }
        path[t]=0; 
        if(!vec[t].size()) flag=1;
    }
    if(flag) cout<<path[b]<<" No";
    else cout<<path[b]<<" Yes";
    return 0;
}




