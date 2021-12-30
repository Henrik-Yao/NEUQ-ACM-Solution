***

# **7-1 双十一**

> 双十一期间，某著名电商平台“东东”为应对销售高峰，准备在n个城市中再增加一个自营仓库，其要求是该仓库设在n个城市中的某个城市，且距离其他所有城市的最短距离之和最小。请编写程序帮助“东东”找出设立仓库的地点。假定n个城市编号为0至n-1，它们之间至少有一个城市与其他所有城市可及。
>
> ### 输入格式:
>
> 输入包含多组数据。每组数据第一行为两个正整数n和e，均不超过100。n表示城市数。接下来e行表示两个城市间的距离信息，每行为3个非负整数a、b、c，其中a和b表示两个城市编号，c表示城市间的距离。
>
> 提示：可使用EOF判断输入结束。
>
> ### 输出格式:
>
> 输出为一个整数，表示建立仓库的城市编号，如多个城市满足要求，则输出编号最小者。
>
> ### 输入样例:
>
> ```in
> 6 5
> 0 1 1
> 0 2 1
> 0 3 1
> 0 4 1
> 0 5 1
> 4 5
> 0 1 1
> 0 2 5
> 1 2 2
> 1 3 4
> 2 3 1
> ```
>
> ### 输出样例:
>
> ```out
> 0
> 1
> ```

这道题就是不计路径的最短路径算法，利用Floyd算法得出任意点到其他点的所有距离，再加和就可以知道最短距离了

```C++
#include <iostream>
#include <cstring>
using namespace std;
#define inf 999999
int main(){
	int city,road;
	while(cin>>city>>road){
		int dp[city][city];
		memset(dp,inf,sizeof dp);
		for(int T=0;T<road;T++){
			int c1,c2,distant;
			cin >> c1 >> c2 >> distant;
			dp[c1][c2]=distant;
			dp[c2][c1]=distant;
		}
		int inter,city1,city2;
		for(inter=0;inter<city;inter++){
			for(city1=0;city1<city;city1++){
				for(city2=0;city2<city;city2++){
					if(dp[city1][city2]>dp[city1][inter]+dp[inter][city2])  dp[city1][city2]=dp[city1][inter]+dp[inter][city2];
				}
			}
		}
		int sum_length[city];
		memset(sum_length,0,sizeof sum_length);
		for(int c=0;c<city;c++){
			for(int csub=0;csub<city;csub++){
				if(c!=csub) sum_length[c]+=dp[c][csub];
			}
		}
		int _min=inf;
		int position=0;
		for(int c=0;c<city;c++){
			if(sum_length[c]<_min){
				position=c;
				_min=sum_length[c];
			}
		}
		cout << position << endl;
	}
}
```

***

# **7-2 路由器**

> 快速的信息传送已经成为必须。信息传送工作由位于网络节点上的路由器来实现。每个路由器都维护一个“路由器表”，给出它可以直接到达的路由器编号。很明显，信息传送要求经过的路由器最少（也被称为“跳数”）。对于给出的网络，要求编写程序发现从信息源到目标节点的最佳路线（最少跳数）。假定n个路由器编号为0至n-1，网络中路由器数目不超过200，且至少有2个路由器，每个路由器最多和50个路由器直接相连。
>
> ### 输入格式:
>
> 输入包含多组测试数据。每组数据输入第一行为整数n和m，表示网络中路由器数。接下来n行表示每个路由器可直接到达的路由器ID列表，每行为一组空格间隔的整数，格式为*i* *k* *v*1 *v*2 ... *v**k*，其中*i*表示路由器编号，*k*为路由器i可直接到达的路由器数，接下来*k*个数 *v*1 *v*2 ... *v**k*表示路由器i可直接到达的路由器编号。接下来m行，表示m组查询，每行两个整数a和b，表示起始路由器和终点路由器编号。
>
> 提示：可使用EOF判断输入结束
>
> ### 输出格式:
>
> 对每组测试数据，输出m行，每行为信息从路由器a传送到路由器b所需经过的最小跳数，如果不可能进行信息传送（起始路由器和终点路由器不连通），则输出“connection impossible”。
>
> ### 输入样例:
>
> ```in
> 6 2
> 0 5 1 2 3 4 5
> 1 0
> 2 0
> 3 0
> 4 0
> 5 0
> 0 2
> 1 2
> 4 2
> 0 2 1 2
> 1 2 2 3
> 2 1 3 
> 3 1 2
> 0 3
> 1 0
> ```
>
> ### 输出样例:
>
> ```out
> 1
> connection impossible
> 2
> connection impossible
> ```

这一题和上一题几乎一样，单纯把单向变成了双向而已。图矩阵写入时需要注意。

```C++
#include <iostream>
#include <cstring>
using namespace std;
#define inf 999999
int main(){
	int n,m;
	while(cin>>n>>m){
		int dp[n][n];
		memset(dp,inf,sizeof dp);
		for(int T=0;T<n;T++){
			int i,cn;
			cin >> i >> cn;
			for(int TT=0;TT<cn;TT++){
				int num;
				cin >> num;
				dp[i][num]=1;
			}
		}
		int inter,router1,router2;
		for(inter=0;inter<n;inter++){
			for(router1=0;router1<n;router1++){
				for(router2=0;router2<n;router2++){
					if(dp[router1][router2]>dp[router1][inter]+dp[inter][router2])  dp[router1][router2]=dp[router1][inter]+dp[inter][router2];
				}
			}
		}
		for(int TTT=0;TTT<m;TTT++){
			int r1,r2;
			cin >> r1 >> r2;
			if(dp[r1][r2] >=inf/2) cout << "connection impossible" << endl;
			else cout << dp[r1][r2] << endl;
		}
	}
	return 0;
}
```

***

# **7-3 最短路径之Dijkstra**

> 本题目要求通过读入无向网的边的信息（省略了各顶点的信息，仅用顶点编号来表示），构造图，并利用Dijkstra算法，求出指定源点到其它各点的最短路径。
>
> ### 输入样例:
>
> 第一行，两个整数，顶点数vN和边数eN。 以后若干行，是相关边的信息，无向图的边是对称的，只输入一半的边（小编号到大编号的，间以空格），最后两行各一个整数，前一个指定源点，后一个指定的查询的终到点。 （注意，示例中34条边，只输入了17条边的信息）
>
> ```in
> 10 34
> 0 1 2
> 0 3 5
> 1 2 5
> 1 3 2
> 2 4 8
> 2 5 4
> 3 5 4
> 3 6 2
> 4 7 5
> 4 5 2
> 5 6 3
> 5 7 9
> 5 8 7
> 6 8 7
> 7 8 3
> 7 9 4
> 8 9 8
> 0
> 8
> ```
>
> ### 输出样例:
>
> 在一行中输出从源点到指定终点的短路径及代价，注意：所有符号均为西文符号。
>
> ```out
> 0-->1-->3-->6-->8:13
> ```

这道题就是模板题。

Dijkstra题见B站动态动画教程。

```C++
#include <iostream>
#include <cstring>
#include <stack>
#define inf 999999
using namespace std;
stack<int> path;
int main(){
	int vN,eN;
	cin >> vN >> eN;
	int tablet[vN][vN];
	memset(tablet,-1,sizeof tablet);
	for(int T=1;T<=eN/2;T++){
		int p1,p2,lv;
		cin >> p1 >> p2 >> lv;
		tablet[p1][p2]=lv;
		tablet[p2][p1]=lv;
	}
	int start,end;
	cin >> start >> end;
    if(start==end){
        cout << start << "-->" << end << ":0" << endl;
        return 0;
    }
	int min_distance[vN],Complete[vN],lastv[vN];
	memset(min_distance,inf,sizeof min_distance);
	memset(Complete,0,sizeof Complete);
	min_distance[start]=0;
	while(Complete[end]==0){
		int minv=inf,minp=0;
		for(int i=0;i<vN;i++){
			if(minv>min_distance[i]&&Complete[i]==0){
				minp=i;
				minv=min_distance[i];
			}
		}
		Complete[minp]=1;
		for(int i=0;i<vN;i++){
			if(tablet[minp][i]!=-1){
				if(min_distance[i]>min_distance[minp]+tablet[minp][i]){
					min_distance[i]=min_distance[minp]+tablet[minp][i];
					lastv[i]=minp;
				}
			}
		}
	}
	int p=end;
	int min_path=min_distance[p];
	while(p!=start){
		path.push(p);
		p=lastv[p];
	}
	cout << start;
	while(!path.empty()){
		cout << "-->" << path.top();
		path.pop();
	}
	cout << ":" << min_path << endl;
	return 0;
}
```

***

# **7-4 最短路径之Floyd**

> 请缩写程序，实现求有向网的最短路径的Floyd算法，因地点可能够是淡泊湖，宁静楼等等，这里简化成编号，要求能够查询出任意两点（用编号表示）间的最短路径及最小距离。
>
> 说明：1）顶点个数上限不超过100；2）距离权值上限不超过9998；
>
> ### 输入格式:
>
> ### 输出格式:
>
> ![QQ图片20201121203429.png](https://images.ptausercontent.com/526008a3-d09c-4a2c-a1cc-08adc4e50165.png)
>
> ### 输入样例:
>
> 第一行，两个整数：vN和eN（图中顶点数和和边数）。 接下来是vN条边的信息：起点，终点，权值（三个数一行，以空格分隔）； 最后两行是待查询的两组起点与终点的编号（每行一个查询，起点与终点编号间也是空格分隔）。
>
> ```in
> 6 8
> 0 5 100
> 0 2 10
> 0 4 30
> 1 2 5
> 2 3 50
> 3 5 10
> 4 3 20
> 4 5 60
> 0 5
> 2 0
> ```
>
> （三块信息：顶点数和边数；边的信息；两组需要查询的顶点信息）
>
> ### 输出样例:
>
> 共输出三行，前两行分别输出两组查询的结果：先是起点到终点的路径说明，再是距离，中间以冒号分隔。如果两个点间不可达，输出距离-1。最后一行是整个可达距离中最大距离的描述(若有多组，输入位置稍前的一组，注意：不包括不可到达的无穷大)。
>
> ```out
> 0->4->3->5:60
> 2->0:-1
> 1->2->3->5:65
> ```

Floyd模板题，需要注意的是Floyd算法较于上面那个算法唯一的好处是可以算负数权值，否则Floyd算法的空间和时间消耗都很高。

```C++
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define inf 999999
vector<int> maxpathc1,maxpathc2;
int main(){
	int city,road;
	cin >> city >> road;
	int dp[city+5][city+5];
	int path[city+5][city+5];
	for(int i=0;i<city;i++) for(int j=0;j<city;j++){
		path[i][j]=j;
		if(i==j) dp[i][j]=0;
	}
	memset(dp,inf,sizeof dp);
	for(int T=0;T<road;T++){
		int c1,c2,distant;
		cin >> c1 >> c2 >> distant;
		dp[c1][c2]=distant;
	}
	int inter,city1,city2;
	for(inter=0;inter<city;inter++){
		for(city1=0;city1<city;city1++){
			for(city2=0;city2<city;city2++){
				if(dp[city1][city2]>dp[city1][inter]+dp[inter][city2])  {
					dp[city1][city2]=dp[city1][inter]+dp[inter][city2];
					path[city1][city2]=path[city1][inter];
				}
			}
		}
	}
	for(int i=0;i<city;i++) dp[i][i]=0;
	for(int TTT=1;TTT<=2;TTT++){
		int start,end;
		cin >> start >> end;
		int i=start,j=end;
        if(start==end) {cout << start << "->" << end << ":0" << endl;continue;}
		if(dp[start][end]>=inf/2){cout << start << "->" << end << ":-1" << endl; continue;}
		int t=start;
		while(t!=end){
			cout << t << "->";
			t=path[t][end];
		}
		cout << end << ":" << dp[start][end] << endl;
	}
	int maxpathstart,maxpathend,maxlength=-inf;
	for(int i=0;i<city;i++) {
		for(int j=0;j<city;j++){
			if(dp[i][j]>=maxlength&&dp[i][j]<=inf/2){
				maxlength=dp[i][j];
			}
		}
	}
	int longest_start=0,longest_end=0;
	bool find=false;
	for(int i=0;i<city;i++) {
		if(find) break;
		for(int j=0;j<city;j++){
			if(dp[i][j]==maxlength){
				longest_start=i;
				longest_end=j;
				find=true;
				break;
			}
		}
	}
	int i=longest_start,j=longest_end;
    if(longest_start==longest_end) {cout << longest_start << "->" << longest_end << ":0" << endl;return 0;}
	if(dp[longest_start][longest_end]>=inf/2){cout << longest_start << "->" << longest_end << ":-1" << endl;return 0;}
	int t=longest_start;
	while(t!=longest_end){
		cout << t << "->";
		t=path[t][longest_end];
	}
	cout << longest_end << ":" << dp[longest_start][longest_end] << endl;
}
```

