### 1. 生化危机

如果目标城市不安全，输出"The city i is not safe!"；

如果安全，从起始点找路到下一个节点，起始点变为下一个节点，直到到达目的地，输出"The city can arrive safely！"；

如果到不了目的地，输出"The city can not arrive safely！"。

```c++
#include<bits/stdc++.h>
using namespace std;
int k,b1[101],b2[101],road[101],safe[51],ans=2,d;
int find(int beginn){
	for(int i=0;i<k;i++){
		if(b1[i]==beginn) 
		    if(safe[b2[i]]&&!road[b2[i]]) road[b1[i]]=1,ans=find(b2[i]);
		if(b2[i]==beginn)
		    if(safe[b1[i]]&&!road[b1[i]]) road[b2[i]]=1,ans=find(b1[i]);//cout<<ans<<endl;
			if(beginn==d) return 1;
			if(ans==1) return 1;
	}
	if(ans!=1) return 0;
}
int main(){
	int m,n,a[51],s;
/**/  int p=0;
	cin>>m>>n>>k;
	for(int i=0;i<=51;i++)
	safe[i]=0;
	for(int i=0;i<n;i++)
	cin>>a[i],safe[a[i]]=1;
	for(int i=0;i<k;i++)
	cin>>b1[i]>>b2[i],road[i]=0;
	cin>>s>>d;
	for(int i=0;i<n;i++)
	if(a[i]==d) p=1;
	if(!p){
	printf("The city %d is not safe!",d);
	return 0;
    }
	ans=find(s);
	if(ans) printf("The city %d can arrive safely!",d);
	else printf("The city %d can not arrive safely!",d);
	return 0;
}
```

### 2.**那就别担心了**

从起始点找路到下一个节点，起始点变为下一个节点，直到到达目的地，每次找到一条完整的路，记录个数，如果有到不了的路，输出no，否则输出yes。

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;

vector<int>G[maxn];

int s, t;
int f[maxn];
int dfs(int u){
	if(f[u])return f[u];
	if(u==t)return 1;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		f[u] += dfs(v);
	}
	return f[u];
}

int ok=1;
int vis[510];
void bfs(){
	queue<int>q;
	q.push(s);
	while(q.size()){
		int tmp = q.front();  q.pop();
		if(vis[tmp])continue;
		vis[tmp] = 1;
		if(f[tmp]==0){
			ok = 0; break;
		}
		if(tmp==t)continue;
		for(int i = 0; i < G[tmp].size(); i++){
			int v = G[tmp][i];
			q.push(v);
		}
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
		int u, v;  cin>>u>>v;
		G[u].push_back(v);
	}
	cin>>s>>t;
	dfs(s);
	cout<<f[s]-f[t]<<" ";
	f[t] = 1;
	bfs();
	if(ok)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
```

### 3.**扫雷游戏**

将所有位置表为-1，有雷的额外标记。

对每次点击进行判断，如果用户点击的方格是已被打开的方格，则点击无效，忽略该点击。如果点击的方格是地雷，则输出“You lose”，程序退出；如果点击的方格不是地雷，则输出点击后的游戏界面，即n行m列整数，每个整数后一个空格，此时若用户获胜，则再输出“You win”。对用户每个有效点击所输出的信息用一个空行间隔。

每个周围无雷的揭开周围8个地方，这8个地方再重复上个动作。



```c++
#include<bits/stdc++.h>
using namespace std;
int space[21][21],lei[21][21];
void find(int c,int d){
	space[c][d]=0;
	int p2=0;
	for(int i=c-1;i<=c+1;i++)
	for(int j=d-1;j<=d+1;j++){
		if(lei[i][j]==-2)space[c][d]++,p2=1;
	}
	if(p2) return;
	else{
		if(space[c-1][d]==-1) find(c-1,d);
		if(space[c+1][d]==-1) find(c+1,d);
		if(space[c][d-1]==-1) find(c,d-1);
		if(space[c][d+1]==-1) find(c,d+1);
		if(space[c-1][d-1]==-1) find(c-1,d-1);
		if(space[c-1][d+1]==-1) find(c-1,d+1);
		if(space[c+1][d-1]==-1) find(c+1,d-1);
		if(space[c+1][d+1]==-1) find(c+1,d+1);	
	}
}
int main(){
	int n,m,k,l,a,b,c,d,p,p3=0;
/**/	cin>>n>>m>>k>>l;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	space[i][j]=-1;
	for(int i=0;i<k;i++)
	cin>>a>>b,lei[a][b]=-2;
	for(int i=0;i<l;i++){
		cin>>c>>d;
        p=0;
		if(lei[c][d]==-2){
			p=0;p=1;break;
		}
		if(space[c][d]>=0)
			continue;	
		find(c,d);
	    for(int i1=0;i1<n;i1++){
		for(int j=0;j<m;j++)
			cout<<space[i1][j]<<" ";
		cout<<endl;
	    }
	    p3=0;
		for(int i1=0;i1<n;i1++){
			for(int j=0;j<m;j++)
			if(space[i1][j]<0){
	//			,cout<<lei[i][j]
					if(lei[i1][j]==-2)
					p=2;
					else{
						p=3;p3=1;break;
					}//	/**/
			}
	        if(p3){p=3;break;}
		}
	//	if(p==3)break;
		if(p==2){cout<<"You win"<<endl;return 0;}
	//	  else cout<<endl;
	    if(i<l)cout<<endl;
	}   
//
	if(p==1){cout<<"You lose"<<endl;return 0;}
}
```

### 4.**01迷宫**

从起始点出发，每到一个新格子，数量加1，最后比较所有路中数量最大的。

```c++
#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,b[1001][1001],g,sc[100001];
char a1[1001][1001];
void ddd(int x1,int y1,int z,int xc){
	if(x1<0||x1>=n||y1<0||y1>=n||b[x1][y1]!=(-1)||a1[x1][y1]-'0'!=z) return;
    b[x1][y1]=xc;
	sc[xc]++;  
	ddd(x1-1,y1,!z,xc); 
	ddd(x1+1,y1,!z,xc);
	ddd(x1,y1-1,!z,xc);
	ddd(x1,y1+1,!z,xc);
}
int main(){
	memset(b,-1,sizeof(b));
	cin>>n>>m;
	for(int i=0;i<=n-1;i++)
	for(int j=0;j<=n-1;j++)
	cin>>a1[i][j];
	for(int i=0;i<=m-1;i++)
	{
		cin>>x>>y;
		x--;y--;
		if(b[x][y]==-1) ddd(x,y,a1[x][y]-'0',i);
		else sc[i]=sc[b[x][y]];	 
	}
	for(int i=0;i<=m-1;i++) cout<<sc[i]<<endl;
	return 0;
}
```











