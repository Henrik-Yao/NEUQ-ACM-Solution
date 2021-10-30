## 7-1生化危机

**解题思路**：

判断是否能够安全到达只需dfs，若中间有一个不安全则无法安全到达

```C++
#include<bits/stdc++.h>
using namespace std;

int safe[55] = {0};
bool book[101] = {false};//是否遍历过 
bool res = false;
vector<vector<int>> road;

void dfs(int s, int t);

int main() {
	int m, n, k; //城市个数，安全城市个数，公路个数 
	cin >> m >> n >> k;
	road.resize(m);
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		safe[t] = 1;
	}
	for(int i = 0; i < k; i++){
		int from, to;
		cin >> from >> to;
		road[from].push_back(to);
		road[to].push_back(from);
	}
	int s, t;//所在城市，目标城市 
	cin >> s >> t;
	book[s] = true;
	dfs(s, t);
	
	
	if(safe[t] == 0){
		cout << "The city " << t << " is not safe!"; 
	}
	else if(res){
		cout << "The city " << t << " can arrive safely!";
	}
	else{
		cout << "The city " << t << " can not arrive safely!";
	}
	

//	for(int i = 0; i < m; i++){
//		for(auto it : road[i]){
//			cout << it << " ";
//		}
//		cout << endl;
//	}
}

void dfs(int s, int t){
	if(s == t || res){
		res = true;
		return;
	}
	for(auto it : road[s]){
		if(res) break;
		if(!book[it]){//没遍历过 
			book[it] = true;
			dfs(it, t);
		}
	}
}
```



## 7-2那就别担心了

**解题思路：**

对节点a进行dfs，dfs返回通过该节点到目的节点不同路径的条数。中间出现了许多重复操作，所以保存结果，记忆化搜索，效率更高。

```C++
#include<bits/stdc++.h>
using namespace std;

int tag[505] = {0};
vector<int> edge[505];
bool res = true;//是否自洽 

int dfs(int from, int to){//返回到 to 的路径数量 
	int now = 0;
	if(tag[from]) return tag[from];
	if(from == to) return 1;
	for(auto it : edge[from]){
		now += dfs(it, to);
	}
	tag[from] = now;
	if(!now) res = false;
	return now;
}

int main() {
	int n, m; //命题个数，推理个数 
	cin >> n >> m;//n个节点，m条边 
	for(int i=1;i<=m;++i)
	{
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
	}
	int from, to;
	cin >> from >> to;
	int k = dfs(from, to);
	
	cout << k;
	if(res) cout << " Yes" << endl;
	else cout << " No" << endl;
}
```



## 7-3扫雷游戏

**分析：主要问题是如果该方格不是地雷的情况**

1. 周围有地雷，需要统计周围地雷的数量填入该方格
2. 周围没有地雷，需要继续打开周围的方格

边界条件：

1. 已经超过游戏边界
2. 周围有地雷
3. 已经被搜索过

```C++
#include<bits/stdc++.h>
using namespace std;

int n, m, k, l;//n行m列 
int open = 0; // 开了open个方格 
int mine[22][22];//没开-1， 有雷-2， 已打开周围无雷0， 有雷x  
bool book[22][22] = {false};
int lr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int ud[8] = {1, 0, -1, -1, -1, 0, 1, 1};

void dfs(int x, int y){
	if(book[x][y] || x < 0 || x >= n || y < 0 || y >= m){
		return;
	}
	book[x][y] = true;
	open++;
	int round = 0;
	for(int i = 0; i < 8; i++){
		int f = x+ud[i];
		int s = y+lr[i];
		if(f >= 0 && f < n && s >= 0 && s < m && mine[f][s] == -2) round++;
	} 

	if(round == 0){//周围全部深度搜索 
		mine[x][y] = 0;
		for(int i = 0; i < 8; i++){
			dfs(x+ud[i], y+lr[i]);
		}
	}
	else{
		mine[x][y] = round;
		return;
	}
}


int main() {
	
	cin >> n >> m >> k >> l;
	int num = n*m-k;
	memset(mine, -1, sizeof(mine));//初始化 
	int x, y;
	for(int i = 0; i < k; i++){//埋入地雷 
		cin >> x >> y;
		mine[x][y] = -2;
	} 
	
	//操作 
	for(int k = 0; k < l; k++){
		cin >> x >> y;
		if(mine[x][y] == -2){
			cout << "You lose";
			return 0;
		}
		if(mine[x][y] != -1) continue;
		dfs(x, y);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mine[i][j] == -2) cout << -1 << " ";
				else cout << mine[i][j] << " ";
			}
			cout << endl;
		}
		if(open == num){
			cout << "You win" << endl;
			return 0;
		} 
		cout << endl;
	} 

}
```



## 7-1 01迷宫

**分析：用dfs可以达成目标，但是m <= 100000，如果每次都dfs会超时，因此重点在于记忆化**

思考对于一个格子dfs，最后dfs到的所有的格子所对应的能移动到的各自都相同记为1组，所以当dfs时还不知道最终结果是多少，因此可以考虑用二维数组go(x,y)储存对应各自的答案标号1，在res数组中保存标号为1的答案即可。即通过res[go(x)(y)]找到对应答案。

（洛谷上有更牛逼的题解！！！）

```C++
#include<bits/stdc++.h>
using namespace std;

int n, m; 
char a[1005][1005];
int go[1005][1005];//去ans[go[x][y]]找答案 
int ans[100005];
int res = 0;
char tag1 = '0';//表示字符为tag1 
char tag2 = '1';

void dfs(int x, int y, int pre, int flag){
	if(x < 1 || x > n || y < 1 || y > n || a[x][y]-'0' != pre || go[x][y] != -1) return;
//	if(go[x][y] != -1){
//		cout << ans[go[x][y]] << endl;
//		return;
//	} 
	
	go[x][y] = flag;
	ans[flag]++;
	
	dfs(x-1, y, !pre, flag);
	dfs(x+1, y, !pre, flag);
	dfs(x, y-1, !pre, flag); 
	dfs(x, y+1, !pre, flag);
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
//		getchar();
	}
	memset(go, -1, sizeof(go));
	int x, y;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		dfs(x, y, a[x][y]-'0', i);
		cout << ans[go[x][y]] << endl;
	} 


}
```

