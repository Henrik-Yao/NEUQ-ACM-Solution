***

# 7-1  **愿天下有情人都是失散多年的兄妹**

~~这谁出的题啊这么诅咒人/xyx~~

> 呵呵。大家都知道五服以内不得通婚，即两个人最近的共同祖先如果在五代以内（即本人、父母、祖父母、曾祖父母、高祖父母）则不可通婚。本题就请你帮助一对有情人判断一下，他们究竟是否可以成婚？

这道题debug了我很久：

有以下误区注意下：

1、父母可以结婚。

2、ID不一定按照顺序。

3、数组开大点。

~~不要在意奇特的变量名~~

```C++
#include <iostream>
#include <vector>
using namespace std;
struct people{
	int ID;
	char SEX;
	int F_ID;
	int M_ID;
}human[1000005];//保存一个人的信息
int ans;// 没用
int NUM;//不需要全局
vector<int>brotheryourfather;
vector<int>sisteryourfather;
void brothersearchyourfather(int n,int fullnum,int ans){
//	printf("BROTHER Searching at %d with ans is %d\n",n,ans);
	if(ans==5||n==-1||n<=0) return;
	else{
		if(human[n].F_ID!=-1) brotheryourfather.push_back(human[n].F_ID);
		if(human[n].M_ID!=-1) brotheryourfather.push_back(human[n].M_ID);
		brothersearchyourfather(human[n].F_ID,fullnum,ans+1);//递归查找父母
		brothersearchyourfather(human[n].M_ID,fullnum,ans+1);
	}
}
void sistersearchyourfather(int n,int fullnum,int ans){//和上面一样（凑行数（bushi
	if(ans==5||n==-1||n<=0) return;
	else{
		if(human[n].F_ID!=-1) sisteryourfather.push_back(human[n].F_ID);
		if(human[n].M_ID!=-1) sisteryourfather.push_back(human[n].M_ID);
		sistersearchyourfather(human[n].F_ID,fullnum,ans+1);
		sistersearchyourfather(human[n].M_ID,fullnum,ans+1);
	}
}
int main(){
	int NUM;
	cin >> NUM;
	int SelfID;
	for(int i=1;i<=1000000;i++){
		human[i].F_ID=-1;
		human[i].M_ID=-1;
		human[i].SEX='N';
	}
	for(int i=1;i<=NUM;i++){
		cin >> SelfID;
		human[SelfID].ID=SelfID;
		cin >> human[SelfID].SEX >> human[SelfID].F_ID >> human[SelfID].M_ID;
		if(human[SelfID].F_ID>=0){
			human[human[SelfID].F_ID].ID=human[SelfID].F_ID;
			human[human[SelfID].F_ID].SEX='M';
		}		
		if(human[SelfID].M_ID>=0){
			human[human[SelfID].M_ID].ID=human[SelfID].M_ID;
			human[human[SelfID].M_ID].SEX='F';
		}
	}
	int gan;
	cin >> gan;
	int brother,sister;
	for(int abc=1;abc<=gan;abc++){
		cin >> brother >> sister;
		if(human[brother].SEX==human[sister].SEX) {cout << "Never Mind" << endl;continue;}
		brotheryourfather.clear();
		sisteryourfather.clear();
		brothersearchyourfather(human[brother].ID,NUM,1);
		sistersearchyourfather(human[sister].ID,NUM,1);
		bool flag=true;
		for(int i=0;i<brotheryourfather.size();i++){//比较两个vector
			for(int j=0;j<sisteryourfather.size();j++){
				if(brotheryourfather[i]==sisteryourfather[j]&&brotheryourfather[i]!=0&&sisteryourfather[i]!=0){flag=false;break;}
			}
		}
		if(flag){cout << "Yes" << endl;continue;}
		else {cout << "No" << endl;continue;}
	}
	return 0;
}
```

***

# 7-2

> X遇到一个关于素数的问题需要你这位大牛帮他解决。素数（prime number）又称质数。一个大于1的自然数，除了1和它本身外，不能整除以其他自然数，换句话说就是该数除了1和它本身以外不再有其他的因数，否则称为合数。哥德巴赫是德国数学家。出生于格奥尼格斯别尔格（现名加里宁城）。曾在英国牛津大学学习。原学法学，由于在欧洲各国访问期间结识了贝努利家族，所以对数学研究产生了兴趣。曾担任中学教师。1725年，到了俄国，同年被选为彼得堡科学院院士。1725年~1740年担任彼得堡科学院会议秘书。1742年，移居莫斯科，并在俄国外交部任职。1742年，哥德巴赫在教学中发现，每个不小于6的偶数都是两个素数之和。如6＝3＋3，14＝3＋11等等。公元1742年6月7日哥德巴赫写信给当时的大数学家欧拉，欧拉在6月30日给他的回信中说，他相信这个猜想是正确的，但他不能证明。叙述如此简单的问题，连欧拉这样首屈一指的数学家都不能证明，这个猜想便引起了许多数学家的注意。我们不需要你去证明哥德巴赫猜想。我们假设哥德巴赫猜想是正确的，一个不小于6的偶数，都是两个素数之和。例如14＝3＋11，也可以表示为14=7+7。现在的问题是给定一个正整数N，求N是最少几个素数的和。。

这是一道数学题。

可以判断出来：

+ 任何一个偶数可以拆成两个奇数，只要这两个奇数加起来等于偶数，必能找到两个两个素数。

+ 一个奇数如果是素数，则就是它本身。

+ 一个奇数如果不是素书，如果它不能拆为2+(素数-2)的形式，只能拆为奇数+偶数，而一个偶数必能拆为两个素数，所以是3个数。

```C++
#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int n){
	if(n<=1) return false;
	else{
		for(int i=2;i<=sqrt(n);i++){
			if(n%i==0) return false;
		}
		return true;
	}
}
int main(){
	int N,n;
	cin >> N;
	for(int abc=1;abc<=N;abc++){
		int sum=0;
		cin >> n;
		if(isprime(n)){sum=1;}
		else if(n%2==0){sum=2;}
		else if(isprime(n-2)){sum=2;}
		else {sum=3;}
		cout << sum << endl;
	}
}
```

***

# 7-3

> 编写程序对给定的有向图（不一定连通）进行深度优先遍历，图中包含n个顶点，编号为0至n-1。本题限定在深度优先遍历过程中，如果同时出现多个待访问的顶点，则优先选择编号最小的一个进行访问，以顶点0为遍历起点。

图遍历

注意是有向图，啊啊啊我在这卡了好久QAQ。

还要注意不一定连通。

用DFS便利即可。

```C++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> num[20005];
vector<int> leaves;
int vis[20005];
void dfs(int n){
	if(vis[n]==1) return;
	if(vis[n]==0){vis[n]=1;leaves.push_back(n);}
//	cout << "P Search at "<< n << endl; 
    if(num[n].size()==0) return;
    else{
    	for(int i=0;i<num[n].size();i++){
    		for(int j=0;j<num[n].size()-1;j++){
    			if(num[n][j]>num[n][j+1]) swap(num[n][j],num[n][j+1]);
			}
		}
        for(int i=0;i<num[n].size();i++){
        	dfs(num[n][i]);
        }
    }
}
int main(){
    int n,e;
    cin >> n >> e;
    int e1,e2;
    for(int abs=0;abs<e;abs++){
        cin >> e1 >> e2;
    //    if(e1>e2) swap(e1,e2);//注意是有向图，这句话不应该加。
        num[e1].push_back(e2);
    }
    for(int i=0;i<n;i++){
		dfs(i);
	}
    leaves[0]=0;;
    bool first=true;
    int op;
    for(int i=0;i<leaves.size();i++) cout << leaves[i] << " ";
    return 0;
}
```

***

# 7-4

>**Drizzle** 前往山地统计大山的数目，现在收到这片区域的地图，地图中用`0（平地）`和`1（山峰）`绘制而成，请你帮忙计算其中的大山数目
>山总是被平地**四面**包围着，每一座山只能在水平或垂直方向上连接相邻的山峰而形成。一座山峰四面被平地包围，这个山峰也算一个大山
>另外，你可以假设地图的四面都被平地包围着。

这道题用广度优先搜索可解（应该

因为广度优先就像是往纸上滴水，扩展的，可以判定非山为边界，把BFS所到之处全部标为访问后，计算山的数量。因为边界不大，可以手动遍历所有点，遇到访问的直接跳，来寻找下一座大山。

```C++
#include <iostream>
#include <queue>
using namespace std;
int _map[2005][2005];
int vis[2005][2005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct point{
	int x;
	int y;
};
int mountain=0;
queue<point> que;
int main(){
	int M,N;
	cin >> M >> N;
	for(int i=1;i<=M;i++) for(int j=1;j<=N;j++) cin >> _map[i][j];
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			if(vis[i][j]==0&&_map[i][j]==1){
				point start;
				start.x=i;
				start.y=j;
				que.push(start);
				vis[start.x][start.y]=1;
				while(!que.empty()){
					start=que.front();
					point next;
					for(int k=0;k<4;k++){
						next.x=start.x+dx[k];
						next.y=start.y+dy[k];
						if(_map[next.x][next.y]==1&&vis[next.x][next.y]==0){
							que.push(next);
							vis[next.x][next.y]=1;
						}
					}
					que.pop();
				}
				mountain++;
			}
		}
	}
	cout << mountain << endl;
	return 0;
}
```

***

# 7-5

>Drizzle 被困到一条充满数字的方块路中，假设这条路由一个非负的整数数组`m`组成，Drizzle 最开始的位置在下标 `start` 处，当他位于下标`i`位置时可以向前或者向后跳跃`m[i]`步数，已知元素值为`0`处的位置是出口，且只能通过出口出去，不可能数组越界，请你通过编程计算出Drizzle能否逃出这里。

这道题可以直接从start开始递归，出不去的条件是无论怎么走，都只能返回已经访问的点，也就是说陷入了死循环，知道这一点就很好写了。

```C++
#include <iostream>
using namespace std;
int vis[50005];
int m[50005];
int n;
bool getout=false;
bool deadloop=false;//没用
void jump(int p){
    if(vis[p]==1||p<0||p>=n) return;
	vis[p]=1;
    if(m[p]==0||getout==true){getout=true;return;}
    else{
        if(p+m[p]>=0&&p+m[p]<n) jump(p+m[p]);
        if(p-m[p]>=0&&p-m[p]<n) jump(p-m[p]);
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> m[i];
    int start;
    vis[start]=1;
    cin >> start;
    jump(start);
    if(getout==true) cout << "True";
    else if(getout==false) cout << "False";
}
```

