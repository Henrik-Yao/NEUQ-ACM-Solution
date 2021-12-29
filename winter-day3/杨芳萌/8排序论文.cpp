#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,first[110],in[110];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
struct edge{
	int end,nxt;
}bian[210];

void addedge(int s,int e){
	cnt++;
	bian[cnt].end = e;
	bian[cnt].nxt = first[s];
	first[s] = cnt;
} 
queue<int> q; 
vector<int> ans;
int getTopo() {
	int flag = 0, multisol = 0;
	for(int i=1; i<=n; i++)
		if(in[i]==0) q.push(i), ++flag;
	if(flag > 1) multisol = 1;
	while(!q.empty()){
		int dian = q.front();
		q.pop();
		ans.push_back(dian);
		flag = 0;
		for(int i=first[dian]; i!=0; i=bian[i].nxt){
			int end = bian[i].end;
			in[end]--;
			if(in[end]==0) q.push(end), flag++;
		}
	    if(flag > 1) multisol = 1;
	}
	if(ans.size()!=n) return 0;
	if(multisol) return 2;
	else return 1;
} 

int main() {
	while(scanf("%d%d",&n,&m)!=EOF) {
	    memset(in, 0, sizeof(in));
	    ans.clear();
	    memset(first, 0, sizeof(first));
	    cnt = 0; memset(bian, 0, sizeof(bian));
		for(int i=1; i<=m; i++) {
			int s,e;
			scanf("%d%d",&s,&e);
			addedge(s,e);
			in[e]++;
		}
		printf("%d\n",getTopo());
	}
    return 0;
}

