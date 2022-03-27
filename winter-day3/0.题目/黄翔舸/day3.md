​                                                                     day3

1思路：.完全图：有(1/2 )n(n-1)条边的无向图称为完全图

有向完全图：有n(n-1)条弧的有向图称为有向完全图

（无向）连通图：对于图中的任意两个顶点之间都是联通的，则称该图是连通图，n个节点的无向连通图最少包含（n-1）条边

对于图的创建，注意联通关系。

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int from;
	int to;
	int weight;
};

bool cmp(node a, node b)
{
	if (a.from != b.from)
		return a.from < b.from;
	return a.to < b.to;
}

node noder[20005];
int counts[20005];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> noder[i].from >> noder[i].to >> noder[i].weight;
		counts[noder[i].from]++;
	}
	
	sort(noder, noder + m, cmp);
	
	int cnt = 0;
	for(int i=0;i<n;++i)
	{
		if (counts[i] == 0) continue;
		int sum = counts[i];
		printf("%d:", noder[cnt].from);
		for (int j = 0; j < sum; ++j)
		{ 
			printf("(%d,%d,%d)", noder[cnt].from, noder[cnt].to, noder[cnt].weight);
			cnt++;
		}
		cout << endl;
	}
	
	return 0;
}

2

思路：无向图删边，判断条件遍历删除对应图边，和图的构建很类似，判断条件用auto x ：并配合erase函数即可。 

#include<bits/stdc++.h>
#include<cstring>
#include<map>
using namespace std;

int main() {
    int n, e, a, b, c, m;
    cin >> n >> e;
    map<int, map<int, int>> tu;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        tu[a][b] = c;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        tu[a].erase(b);
    }
    for (auto i : tu) {
        int a = i.first;
        string s = "";
        for (auto j : i.second) {
            s += "(" + to_string(a) + "," + to_string(j.first) + "," + to_string(j.second) + ")";
        }
        if (s != "") cout << a << ":" << s << endl;
    }
    return 0;
}

4

思路：岛屿数量和之前考试的山很相似，遍历判断图的成立，并将联通的岛屿扩大（如果满足条件），不能只以最小岛屿判断。

#include <iostream>
using namespace std;
int a[2001][2001],b[2001][2001],sum=0;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,m;
void dfs(int x,int y)
{
    int i;
    for(i=0;i<4;i++)
    {
        int X=x+dx[i],Y=y+dy[i];
        if(X>=0&&Y>=0&&X<=n&&Y<=m&&a[X][Y]==1&&b[X][Y]==0)
        {
            b[X][Y]=1;
            dfs(X,Y);
        }
    }
}
int main()
{
    int i,j;
    cin>>m>>n;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(a[i][j]==1&&b[i][j]==0)
            {
                dfs(i,j);
                sum++;
            }
            cout<<sum;
}

5

思路：在图的基础上要求路越少越好即路越长越好，可以深度遍历，在回去搜寻通路。

#include<bits/stdc++.h>
using namespace std;

struct stu {
	int u;
	int v;
	int c;
};
vector<stu> v;
int fa[10001];

bool cmp(stu x,stu y) {
	return x.c<y.c;
}
int find(int x) {
	if(fa[x]==x)
		return x;
	else
		return fa[x]=find(fa[x]);
}

void lh(int x,int y) {
	int f1=find(x);
	int f2=find(y);
	if(f1!=f2)
		fa[f1]=f2;
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0; i<m; i++) {
		stu x;
		cin>>x.u>>x.v>>x.c;
		v.push_back(x);
	}
	int x=0,max=0;
	for(int i=0; i<n; i++)
		fa[i]=i;
	sort(v.begin(),v.end(),cmp);
	for(int i=0; i<m; i++) {
	if(find(v[i].u)!=find(v[i].v)) {
			lh(v[i].u,v[i].v);
			if(max<v[i].c)
				max=v[i].c;
			x++;
		}
	}
	cout<<x<<" "<<max;
	    return 0;
}6

思路：建立结构体数组，判断权值比较大小，记录改组数据，输出。

#include <iostream>
#include<algorithm>
using namespace std;

typedef struct {
	int d1;
	int d2;
	int qz; 
}xx;
int a[201];

bool bj(xx xx1, xx xx2) {
	return xx1.qz < xx2.qz;
}

void init() {
	for (int i = 0; i < 201; i++) {
		a[i] = i;
	}
}

int ss(int x) {
	int r = x;
	while (a[r] != r)
		r = a[r];
	return r;
}

int jr(int x, int y) {
	int fx = ss(x);
	int fy = ss(y);
	if (fx != fy) {
		a[fy] = fx;
		return 1;
	}
	return 0;
}

int main() {
	int n, e;
	while (cin >> n >> e) {
		xx xx[e];
		init();
		for (int i = 0; i < e; i++) {
			cin >> xx[i].d1 >> xx[i].d2>> xx[i].qz;
		}
		sort(xx, xx+ e, bj); 
		int cnt = 0, w_sum = 0; 
		for (int i = 0; i < e; i++) {
			if (jr(xx[i].d1, xx[i].d2)) {
				cnt++;
				w_sum += xx[i].qz;
			}
			if (cnt == n - 1)
				break;
		}
		if (cnt == n - 1)
			cout << w_sum << endl;
		else cout << "There is no minimum spanning tree." << endl;
	}

	return 0;

}

7

思路：在深度的遍历无向图的基础上加了一个限制条件，有一个特殊的城市只能经过两次，构建一个flag，用来判断是否可以再次经过，遍历比较方案公路，改造方案最优解。

#include <algorithm>
#include <iostream>
using namespace std;

typedef struct {
    int u;
    int v;
    int w;
} Road;

Road road[51];
int f[51];

bool cmp(Road r1, Road r2) { return r1.w < r2.w; }

void init() {
    for (int i = 0; i < 51; i++) {
        f[i] = i;
    }
}

int find(int x) {
    if (x == f[x])
        return x;
    return f[x] = find(f[x]);
}

int merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        f[b] = a;
        return 1;
    }
    return 0;
}

int main() {
    int n, v, e;
    int flag = 0;
    while (scanf("%d %d %d", &n, &v, &e) != EOF) {
        flag++;
        if (flag == 1)
        {

        }
        else
        {
            cout << endl;
        }
        init();
        for (int i = 0; i < e; i++) {
            scanf("%d %d %d", &road[i].u, &road[i].v, &road[i].w);
        }
        int cnt = 0, sum = 0, num = 0;
        sort(road, road + e, cmp);
        for (int i = 0; i < e; i++) {
            if ((road[i].u == v || road[i].v == v) && cnt < 2) {
                if (merge(road[i].u, road[i].v)) {
                    sum += road[i].w;
                    cnt++;
                    num++;
                }
            }
            else if (road[i].u != v && road[i].v != v) {
                if (merge(road[i].u, road[i].v)) {
                    sum += road[i].w;
                    num++;
                }
            }
            if (num == n - 1)
                break;
        }
        if (num == n - 1 && cnt <= 2)
        {
            printf("%d", sum);


​         
        }
        else
            printf("-1");
       
    }
    return 0;
}