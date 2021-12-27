#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct people{
	string name;
	int time;
	int w;
	int pos;
}r[10001];
int vis[10001];
map<string,int>group;
vector<string> temp[101];
queue<people>q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	string str;	
	for (int i=1;i<=m;i++){
		int num;
		cin>>num;
		for (int j=1;j<=num;j++){
			cin>>str;
			temp[i].push_back(str);
			group[str]=i;
		}
	}
	for (int i=1;i<=n;i++){
		cin>>r[i].name>>r[i].time>>r[i].w;
		r[i].w=min(60,r[i].w);
		r[i].pos=i;
		q.push(r[i]);
	}
	int tot=0,last=0;
	while (!q.empty()){
		people cur=q.front();
		q.pop();
		if (vis[cur.pos]) continue;
		vis[cur.pos]=1;
		if (cur.time<=last){
			tot+=last-cur.time;
			last+=cur.w;
		}
		else {
			last=cur.time+cur.w;
		}
		cout<<cur.name<<endl;
		for (int i=cur.pos+1;i<=n;i++){
			if (r[i].time>last) break;
			if (cur.name!=r[i].name&&!vis[i]&&group.count(cur.name)&&group.count(r[i].name)&&group[cur.name]==group[r[i].name]){
				vis[i]=1;
				cout<<r[i].name<<endl;
				tot+=last-r[i].time;
				last+=r[i].w;
			}
		}
	}
	cout<<fixed<<setprecision(1)<<tot/(double)n; 
	return 0;
} 
