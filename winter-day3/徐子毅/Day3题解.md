***

### # **7-1 图的创建**

> 请编写程序创建一个有向图。有向图中包含n个顶点，编号为0至n-1。
>
> ### 输入格式:
>
> 输入第一行为两个正整数n和e，分别表示图的顶点数和边数，其中n不超过20000，e不超过20000。接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，c表示权值。各边并非按端点编号顺序排列。
>
> ### 输出格式:
>
> 按顶点编号递增顺序输出每个顶点引出的边，每个顶点占一行，若某顶点没有引出边，则不输出。每行表示一个顶点引出的所有边，格式为a:(a,b,w)……，表示有向边a->b的权值为w，a引出的多条边按编号b的递增序排列。
>
> ### 输入样例:
>
> ```in
> 7 7
> 0 1 5
> 0 3 7
> 0 6 6
> 1 2 4
> 2 5 1
> 3 5 3
> 6 5 4
> ```
>
> ### 输出样例:
>
> ```out
> 0:(0,1,5)(0,3,7)(0,6,6)
> 1:(1,2,4)
> 2:(2,5,1)
> 3:(3,5,3)
> 6:(6,5,4)
> ```

最简单的有向图的创立和遍历，这里我用的二维map数组创建的，不知为何我用二维数组会超时。

```C++
#include <iostream>
#include <map>
using namespace std;
int main(){
    int point,line;
    map<int,map<int,int>> tablet;
    cin >> point >> line;
    for(int i=0;i<line;i++){
        int n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        if(n1==n2) continue;
        tablet[n1][n2]=n3;
    }
    map<int,map<int,int>>::iterator Iter1;
    map<int,int>::iterator Iter2;
    for(Iter1=tablet.begin();Iter1!=tablet.end();Iter1++){
        string str="";
        for(Iter2=Iter1->second.begin();Iter2!=Iter1->second.end();Iter2++){
            str+="("+to_string(Iter1->first)+","+to_string(Iter2->first)+","+to_string(Iter2->second)+")";
        }
        cout <<Iter1->first<< ":" << str <<endl;
    }
    return 0;
}
```

***

 # **7-2 图的删边操作**

> 请编写程序对给定的有向图删除若干条边。有向图中包含n个顶点，编号为0至n-1。
>
> ### 输入格式:
>
> 输入第一行为两个正整数n和e，分别表示图的顶点数和边数，其中n不超过20000，e不超过1000。接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，c表示权值。各边并非按端点编号顺序排列。随后一行为一个整数k，表示删除的边的条数，接下来k行，每行为2个非负整数a、b，表示待删除的边为a->b。保证删除的边一定在原图中。
>
> ### 输出格式:
>
> 输出执行删边操作之后的图。每行表示一个顶点引出的所有边，格式为a:(a,b,w)……，表示有向边a->b的权值为w，a引出的多条边按编号b的递增序排列。若某顶点没有引出边，则不输出。
>
> ### 输入样例:
>
> ```in
> 7 7
> 0 1 5
> 0 3 7
> 0 6 6
> 1 2 4
> 2 5 1
> 3 5 3
> 6 5 4
> 2
> 2 5
> 0 1
> ```
>
> ### 输出样例:
>
> ```out
> 0:(0,3,7)(0,6,6)
> 1:(1,2,4)
> 3:(3,5,3)
> 6:(6,5,4)
> ```

和上题神似，这道题比起上一题只需要erase一下需要删除的map就可以了：

```C++
cin >> needdelete;
    for(int i=0;i<needdelete;i++){
        int n1,n2;
        cin >> n1 >> n2;
        tablet[n1].erase(n2);
    }
```

```C++
#include <iostream>
#include <map>
using namespace std;
map<int,map<int,int>> tablet;
int main(){
    int point,line,needdelete;
    cin >> point >> line;
    for(int i=0;i<line;i++){
        int n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        tablet[n1][n2]=n3;
    }
    cin >> needdelete;
    for(int i=0;i<needdelete;i++){
        int n1,n2;
        cin >> n1 >> n2;
        tablet[n1].erase(n2);
    }
    map<int,map<int,int>>::iterator Iter1;
    map<int,int>::iterator Iter2;
    for(Iter1=tablet.begin();Iter1!=tablet.end();Iter1++){
        bool first=true;
        bool have=false;
        for(Iter2=Iter1->second.begin();Iter2!=Iter1->second.end();Iter2++){
            if(Iter2->second!=0){
                if(first){
                    cout << Iter1->first << ":(" << Iter1->first << "," << Iter2->first << "," << Iter2->second << ")";
                    first=false;
                }else cout << "(" << Iter1->first << "," << Iter2->first << "," << Iter2->second << ")";
                have=true;
            }
        }
        if(have) cout << endl;
    }
    return 0;
}
```

***

# **7-4 岛屿数量**

> 给你一个由 1（陆地）和 0（水）组成的n*m的二维网格，请你计算网格中岛屿的数量num。
>
> 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。例如
>
> | 例   | 例   | 例   |
> | ---- | ---- | ---- |
> | 0    | 0    | 0    |
> | 0    | 1    | 0    |
> | 0    | 0    | 1    |
>
> 此为两个岛屿
>
> 此外，你可以假设该网格的四条边均被水包围。1<=n,m<=100
>
> ### 输入格式:
>
> 第一行中给出网格长宽n,m 接下来的n行表示网格情况
>
> ### 输出格式:
>
> 岛屿个数num
>
> ### 输入样例:
>
> 在这里给出一组输入。例如：
>
> ```in
> 4 5
> 1 1 0 0 0
> 1 1 0 0 0
> 0 0 1 0 0
> 0 0 0 1 1
> ```
>
> ### 输出样例:
>
> 在这里给出相应的输出。例如：
>
> ```out
> 3
> ```

~~这部原题？~~

这道题可以直接bfs搜索，首先是直接遍历地图，碰到1而且这个位置还没被访问时，就直接bfs标记所有的1,当队列中为空的时候，岛屿数量+1即可。

```C++
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
				island++;
			}
		}
	}
	cout << island << endl;
	return 0;
}
```

***

#  **7-5 繁忙的都市**

> 城市 C 是一个非常繁忙的大都市，城市中的道路十分的拥挤，于是市长决定对其中的道路进行改造。城市 C 的道路是这样分布的：城市中有 *n* 个交叉路口，有些交叉路口之间有道路相连，两个交叉路口之间最多有一条道路相连接。这些道路是双向的，且把所有的交叉路口直接或间接的连接起来了。每条道路都有一个分值，分值越小表示这个道路越繁忙，越需要进行改造。但是市政府的资金有限，市长希望进行改造的道路越少越好，于是他提出下面的要求：
>
> 1. 改造的那些道路能够把所有的交叉路口直接或间接的连通起来。
> 2. 在满足要求 (1) 的情况下，改造的道路尽量少。
> 3. 在满足要求 (1)、(2) 的情况下，改造的那些道路中分值最大的道路分值尽量小。
>
> 任务：作为市规划局的你，应当作出最佳的决策，选择那些道路应当被修建。
>
> ### 输入格式:
>
> 第一行有两个整数 *n*,*m* 表示城市有 *n* 个交叉路口，*m* 条道路。
>
> 接下来 *m* 行是对每条道路的描述，*u*,*v*,*c* 表示交叉路口 *u* 和 *v* 之间有道路相连，分值为 *c* 。
>
> ### 输出格式:
>
> 两个整数 *s*,*ma**x*，表示你选出了几条道路，分值最大的那条道路的分值是多少。
>
> ### 输入样例:
>
> ```in
> 4 5
> 1 2 3
> 1 4 5
> 2 4 7
> 2 3 6
> 3 4 8
> ```
>
> ### 输出样例:
>
> ```out
> 3 6
> ```

这事最小生成树我用的是Kruskal算法，这个算法最直接，直接挑选权值最小的路径就可以了。同时判断有没有成环，判断有没有成环时需要用的查并集。

```C++
#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int p1,p2;
    int w;
};
int father[20005];
edge e[20005];
int _rank[20005];
bool cmp(edge e1,edge e2){
    if(e1.w!=e2.w) return e1.w<e2.w;
    else return e1.p1<e2.p2;
}
int find_father(int x){
     return father[x]==x?x:father[x]=find_father(father[x]);
}
int main(){
    int vertices,edges;
    cin >> vertices >> edges;
    int n1,n2,n3;
    for(int i=0;i<edges;i++){
        cin >> e[i].p1 >> e[i].p2 >> e[i].w;
        father[e[i].p1]=e[i].p1;
        father[e[i].p2]=e[i].p2;
        _rank[e[i].p1]=1;
        _rank[e[i].p2]=1;
    }
    sort(e,e+edges,cmp);
    int in_line=0;
    int max_w=0;
    for(int i=0;i<edges,in_line<vertices-1;i++){
        int f1=find_father(e[i].p1);
        int f2=find_father(e[i].p2);
        if(f1!=f2){
            if(_rank[f1]<_rank[f2]) father[f1]=f2;
            else if(_rank[f2]<_rank[f1]) father[f2]=f1;
            else{
                father[f1]=f2;
                _rank[f2]++;
            }
            in_line++;
            if(e[i].w>max_w) max_w=e[i].w;
        }
    }
    cout <<vertices-1 << " " <<  max_w << endl;
}
```

***

# **7-6 最小支撑树**

> 给定一个包含n个顶点的正权无向图，编号为1至n。请编写程序求出其最小支撑树，并计算其边权之和。
>
> ### 输入格式:
>
> **输入包含多组数据。**每组数据第一行为2个整数n和e，均不超过1500，分别表示图的顶点数和边数。接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，c表示权值，不超过100。各边并非按端点编号顺序排列。
>
> ### 输出格式:
>
> 对于每组数据，若存在最小支撑树则输出一个整数，为最小支撑树各边权值之和；若不存在最小支撑树，则输出“There is no minimum spanning tree.”。
>
> ### 输入样例:
>
> ```in
> 4 5
> 1 2 1
> 1 4 1
> 2 4 5
> 2 3 1
> 3 4 8
> 4 2
> 1 2 1
> 3 4 8
> ```
>
> ### 输出样例:
>
> ```out
> 3
> There is no minimum spanning tree.
> ```

这是直接把最小生成树告知了。。。

判断没有最小生成树的方法就是生成的路径条数不是节点数-1。

```C++
#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int p1,p2;
    int w;
};
int father[1505];
edge e[1505];
int _rank[1505];
bool cmp(edge e1,edge e2){
    if(e1.w!=e2.w) return e1.w<e2.w;
    else return e1.p1<e2.p2;
}
int find_father(int x){
     return father[x]==x?x:father[x]=find_father(father[x]);
}
int main(){
    int vertices,edges;
    while(cin >> vertices >> edges){
        int n1,n2,n3;
		for(int i=0;i<1005;i++){
			father[i]=0;_rank[i]=0;e[i]={0,0,0};
		}
        for(int i=0;i<edges;i++){
            cin >> e[i].p1 >> e[i].p2 >> e[i].w;
	        father[e[i].p1]=e[i].p1;
	        father[e[i].p2]=e[i].p2;
	        _rank[e[i].p1]=1;
	        _rank[e[i].p2]=1;
	    }
	    sort(e,e+edges,cmp);
	    int in_line=0;
	    int sum=0;
	    for(int i=0;i<edges;i++){
			if(in_line==vertices-1) break;
	        int f1=find_father(e[i].p1);
	        int f2=find_father(e[i].p2);
	        if(f1!=f2){
	            if(_rank[f1]<_rank[f2]) father[f1]=f2;
	            else if(_rank[f2]<_rank[f1]) father[f2]=f1;
	            else{
	                father[f1]=f2;
	                _rank[f2]++;
	            }
	            in_line++;
		        sum+=e[i].w;
        	}
	    }
	    if(in_line==vertices-1) cout << sum << endl;
		else cout << "There is no minimum spanning tree." <<endl;
	}
}
```

***

# **7-7 特殊最小成本修路**

> n个城镇之间目前有一些道路连接，但道路都是年久失修的土道。现在政府准备将其中一些土道改造为标准公路，希望标准公路能够将所有城镇连通且总成本最小，**但其中有一个城镇比较特殊，受地形等限制，最多只能有两条标准公路通过该镇**。请编写程序，找出一种满足上述条件的、总成本最小的改造方案，若不存在改造方案，则亦能识别。假定道路是双向的。
>
> ### 输入格式:
>
> 输入包含多组数据。每组数据第一行是3个整数n、v和e，均不超过50，n为城镇数目，城镇编号0至n-1。v为最能有两条标准公路的城镇编号，e为现有的土路条数，接下来是e行表示每条道路信息，每行为3个非负整数a、b、c，表示城镇a和城镇b间现有一条道路，若将其改造为标准公路，成本为c。
>
> ### 输出格式:
>
> 对每组数据输出一行，为一个整数，表示满足要求的最小成本，若不存在改造方案，则输出-1。
>
> ### 输入样例:
>
> ```in
> 5 0 8
> 0 1 1
> 0 2 1
> 0 3 1
> 0 4 1
> 1 4 100
> 1 2 100
> 2 3 100
> 3 4 100
> 5 0 4
> 0 1 1
> 0 2 1
> 0 3 1
> 0 4 1
> ```
>
> ### 输出样例:
>
> ```out
> 202
> -1
> ```

这道题就是在碰到节点的时候需要判断一下有没有特殊节点，有特殊节点的时候就要判断一下道路条数进行区分建还是不建。

```C++
#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int p1,p2;
    int w;
};
int father[105];
edge e[105];
int _rank[105];
bool cmp(edge e1,edge e2){
    if(e1.w!=e2.w) return e1.w<e2.w;
    else return e1.p1>e2.p2;
}
int find_father(int x){
     return father[x]==x?x:father[x]=find_father(father[x]);
}
void Merge(int f1,int f2){
	if(_rank[f1]<_rank[f2]) father[f1]=f2;
	else if(_rank[f2]<_rank[f1]) father[f2]=f1;
	else{
	    father[f1]=f2;
	    _rank[f2]++;
	}
}
int main(){
    int vertices,edges,brokencity;
    while(cin >> vertices >> brokencity >> edges){
        int n1,n2,n3;
		for(int i=0;i<105;i++){
			father[i]=0;_rank[i]=0;e[i]={0,0,0};
		}
        for(int i=0;i<edges;i++){
            cin >> e[i].p1 >> e[i].p2 >> e[i].w;
	        father[e[i].p1]=e[i].p1;
	        father[e[i].p2]=e[i].p2;
	        _rank[e[i].p1]=1;
	        _rank[e[i].p2]=1;
	    }
	    sort(e,e+edges,cmp);
	    int in_line=0;
		int NumConnecttoBrokenCity=0;
	    int sum=0;
	    for(int i=0;i<edges;i++){
	        int f1=find_father(e[i].p1);
	        int f2=find_father(e[i].p2);
	        if(f1!=f2){
				if((e[i].p1==brokencity||e[i].p2==brokencity)&&NumConnecttoBrokenCity<2){
					Merge(f1,f2);
					NumConnecttoBrokenCity++;
					sum+=e[i].w;
					in_line++;
				}
				if(e[i].p1!=brokencity&&e[i].p2!=brokencity){
					Merge(f1,f2);
					sum+=e[i].w;
					in_line++;
				}
				if(in_line==vertices-1) break;
        	}
	    }
	    if(in_line==vertices-1) cout << sum << endl;
		else cout << -1 <<endl;
	}
}
```

