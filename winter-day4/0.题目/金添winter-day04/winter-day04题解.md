# winter-day04���
### 7-1�ܼ򵥵���С·�����⣬����ͨ�����������㷨����ģ�⡣
```C++
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
typedef pair<__int128, int> PII;

inline __int128 read(){
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void print(__int128 x){
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int h[N], e[M], ne[M], idx;
int h2[N], e2[M], ne2[M], idx2;
__int128 w1[M], w2[M];
__int128 val[N];
int n, m, q;
__int128 d1[N], d2[N];
bool st[N];

void add(int a, int b, __int128 x)
{
    e[idx] = b, w1[idx] = x, ne[idx] = h[a], h[a] = idx++;
}
void add2(int a, int b, __int128 y)
{
    e2[idx2] = b, w2[idx2] = y, ne2[idx2] = h2[a], h2[a] = idx2++;
}

void dij1()
{
    memset(d1, 0x3f, sizeof(d1));
    d1[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;

        if(st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (d1[j] > t.first + w1[i])
            {
                d1[j] = t.first + w1[i];
                heap.push({d1[j], j});
            }
        }
    }
}

void dij2()
{
    memset(st, 0, sizeof(st));
    memset(d2, 0x3f, sizeof(d2));
    d2[n] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, n});

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;

        if(st[ver]) continue;
        st[ver] = true;

        for (int i = h2[ver]; ~i; i = ne2[i])
        {
            int j = e2[i];
            if (d2[j] > t.first + w2[i])
            {
                d2[j] = t.first + w2[i];
                heap.push({d2[j], j});
            }
        }
    }
}


int main()
{
    memset(h, -1, sizeof(h));
    memset(h2, -1, sizeof(h2));
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m;i++)
    {
        int u, v;
        __int128 a, b;
        scanf("%d%d", &u, &v);
        a = read();
        b = read();
        if (u == v)
            continue;
        add(u, v, a);
        add2(v, u, b);
    }
    for (int i = 1; i <= n;i++)
    {
        val[i] = read();
    }
    dij1();
    dij2();

    set<PII> s;

    for (int i = 1; i <= n;i++)
    {
        if (d1[i] >= INF || d2[i] >= INF) continue;
        s.insert({d1[i] + ((d2[i] + val[i] - 1) / val[i]), i});
    }
    /*puts("");

    __int128 minv = INF;
    int t;
    for (int i = 1; i <= n;i++)
    {
        if (d1[i] >= INF || d2[i] >= INF) continue;
        if (minv > d1[i] + ((d2[i] + val[i] - 1) / val[i]))
        {
            minv = d1[i] + ((d2[i] + val[i] - 1) / val[i]);
            t = i;
            //print(maxv);
            //puts("");
        }
    }*/
    /*for (int i = 1; i <= n;i++)
    {
        print(d1[i]);
        cout << ' ';
        print(d2[i]);
        puts("");
    }*/

    for (int i = 0; i < q; i++)
    {
        int x;
        __int128 y;
        scanf("%d", &x);
        y = read();
        

        if (d1[x] >= INF || d2[x] >= INF)
        {
            auto x = s.begin();
            print(x->first);
        }

        else
        {
            s.erase({d1[x] + ((d2[x] + val[x] - 1) / val[x]), x});
            val[x] = y;
            s.insert({d1[x] + ((d2[x] + val[x] - 1) / val[x]), x});
            auto x = s.begin();
            print(x->first);
        }

        puts("");
    }
    return 0;
}
```
### 7-2 ·����
Ҳ��ͨ�����������㷨����ģ�⡣
```C++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; // n��·����,m��ѯ��
    while (cin >> n >> m)
    {
        int map[100][100];
        memset(map, 0x3f, sizeof(map)); //���������㷨��ʼ��ֵΪ0x3f��0x7f̫�󣬻����
        for (int i = 0; i < n; i++)
        {
            int z, num;
            cin >> z >> num;
            for (int j = 0; j < num; j++)
            {
                int remp;
                cin >> remp;
                map[i][remp] = 1; //ÿ��һ����ΪȨֵΪ1
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (i == j)
                {
                    map[i][j] = 0;
                }
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (map[i][j] > map[i][k] + map[k][j])
                    {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            int remp1, remp2;
            cin >> remp1 >> remp2;
            if (map[remp1][remp2] >= 100)
                cout << "connection impossible" << endl;
            else
                cout << map[remp1][remp2] << endl;
        }
    }

    return 0;
}
```
### 7-3 ���·��֮Dijkstra
�Ͻ�˹�����㷨��ͨ��ÿ�ҵ�һ�������͵ĵ㽫�� ��Ϊ�׵㣬�Ӷ�������������и��ı��.
```C++
#include <bits/stdc++.h>
using namespace std;
// Dijkstra �Ͻ�˹�����㷨
int path[3000]; //��¼·��
void dfs(int x)
{
    if (path[x] != -1)
    {
        dfs(path[x]);
    }
    else
        return;
    cout << "-->" << x;
}
   int n, e;            //�������ͱ���
    int G[3000][3000]; //����ͼ
 
int main()
{
    cin >> n >> e;
    memset(G, 0x3f, sizeof G);
    for (int i = 0; i < e / 2; i++)
    {
        int remp1, remp2, remp3;
        cin >> remp1 >> remp2 >> remp3;
        G[remp1][remp2] = remp3;
        G[remp2][remp1] = remp3;
    }
    int start, end;
    cin >> start >> end;
    int dis[5000]; //��㵽�������̾���
    memset(path, -1, sizeof path);
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = 0; //���������Ϊ��
    bool visit[5090];
    memset(visit,0,sizeof(visit));
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if ((u == -1 || dis[u] > dis[j]) && !visit[j])
            {
                u = j;
            }

        } // ÿ��Ѱ��dis��С�Ľڵ�����
        if (u == -1)
            break;
        visit[u] = 1;
        for (int j = 0; j < n; j++)
        {
            if (G[u][j] == 0x3f3f3f3f)
                continue;
            if (dis[u] + G[u][j] < dis[j]) //ÿ���Ե�ǰ�����С�ĵ�Ϊ���ģ�����������������
            {
                dis[j] = dis[u] + G[u][j];
                path[j] = u;
            }
        }
    }
    cout << start;
    if(start==end)
    {
        cout<<"-->"<<end;
    }
    else
    {
        dfs(end);
    }
    cout << ":";
    cout << dis[end];
    return 0;
}
```
### 7-4 ���·��֮Floyd
�������������ӡ���ؼ��ǹ���һ�������ڵϽ�˹�����㷨��ǰ�����飬���õ�ʱ��ȥ���飬Ч����ͬ��
```C++
#include <bits/stdc++.h>
using namespace std;
int map1[1000][1000];
int path[1000][1000];
//floyed �㷨ʵ����·����ӡ
//path �����¼
int main()
{
    int n, m; // nΪ������,mΪ����
    cin >> n >> m;
    memset(map1, 0x3f, sizeof(map1));
    for (int i = 0; i < m; i++)
    {
        int remp1, remp2, remp3;
        cin >> remp1 >> remp2 >> remp3;
        map1[remp1][remp2] = remp3;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            path[i][j] = j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i == j)
            {
                map1[i][j] = 0;
            }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map1[i][j] > map1[i][k] + map1[k][j])
                {
                    map1[i][j] = map1[i][k] + map1[k][j];
                    path[i][j] =path[i][k];
                }
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<map1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for (int i = 0; i < 2; i++)
    {
        int remp1, remp2;
        cin >> remp1 >> remp2;
        if(remp1==remp2)
        cout<<remp1<<"->"<<remp2<<":"<<0<<endl;
        else
        {
            int start=remp1;
            int end=remp2;
            cout<<start;
            while(start!=end)
            {
                cout<<"->"<<path[start][end];
                start=path[start][end];
            }
            if(map1[remp1][remp2]<9998)
            cout<<":"<<map1[remp1][remp2]<<endl;
            else
            cout<<":"<<-1<<endl;
        }
    }
    int max_distace=-9998;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map1[i][j]>max_distace&&(map1[i][j]<9998&&map1[i][j]>-9998))
            {
                max_distace=map1[i][j];
            }//�ҵ����������
        }
    }
    int max_start=-99998,max_end=-99998;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(max_distace==map1[i][j])
            {
                max_start=i;
                max_end=j;
            }
        }
    }
    int remp_start=max_start,remp_end=max_end;
    if(max_start==max_end)
    cout<<max_start<<"->"<<max_end<<endl;
    else 
    {
        cout<<max_start;
        while(max_start!=max_end)
        {
            cout<<"->"<<path[max_start][max_end];
            max_start=path[max_start][max_end];
        }
        cout<<":"<<map1[remp_start][remp_end];
    }
    return 0;
}
```
### 7-5 �Թ�����-���·��
�ؼ��ǻ��ݣ����ݣ����ݣ�
̰��+�Ͻ�˹����
```C++
#include <bits/stdc++.h>
using namespace std;
int l,w;                //l����w��
int start_x, start_y, end_x, end_y; //��㣬�յ�
int map1[100][100]; //��¼ͼ
int dis[100][100];  //��¼��㵽����һ��ľ���(������ֵ)
int ans[100][2];      //�����մ𰸵���������
int path[100][2];     //�浽���е��ͨ��·��(��ʱ����)
int dirx[4]={0,0,-1,1};
int diry[4]={1,-1,0,0}; //λ�Ʊ���
int cnt=0;              //��¼����·��·�߾�������
int sum=0;              //��¼���մ𰸵ľ�������
void search(int x,int y)
{
    if(x==end_x&&y==end_y)
    {
        for(int i=0;i<cnt;i++)
        {
            ans[i][0]=path[i][0];
            ans[i][1]=path[i][1];//·�����óɹ�����·������������·����
        }
        sum=cnt;    //·������ֵ
        return;
    }
    for(int i=0;i<4;i++)
    {
        int dx=x+dirx[i];
        int dy=y+diry[i];
        if(map1[dx][dy]!=-1&&(dx<l&&dx>=0)&&(dy<=w&&dy>=0)&&dis[x][y]+map1[dx][dy]<dis[dx][dy])
        {
            //�����㣬˵���ǿ���ѡ����н��
            dis[dx][dy]=dis[x][y]+map1[dx][dy];
            path[cnt][0]=dx;
            path[cnt][1]=dy;
            cnt++;
            search(dx,dy);
            cnt--; //�ؼ��еĹؼ���һ��Ҫ���ݣ��������·���ܵ��յ㣬ֱ��һ��һ����ݣ��׳������á�
        }
    }
}
int main()
{
    memset(dis,0x3f,sizeof(dis));
    cin >> l >> w;
    cin >> start_x >> start_y >> end_x >> end_y;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cin >> map1[i][j];
        }
    }
    int s=start_x,e=start_y;
    dis[s][e]=map1[s][e];  //������ȸ���
    path[cnt][0]=s;
    path[cnt][1]=e;      //���������·����
    cnt++;
    search(s,e);
    for(int i=sum-1;i>=0;i--)
    cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<")";
    return 0;
}
/*
10 10
3 6 8 8
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1  2  1  1  1  1  1  5  1 -1
-1  1  9  9  9  1  1 -1  1 -1
-1  1  1  1  1  1  1 -1  1 -1
-1  1 -1 -1 -1 -1 -1 -1  1 -1
-1  1  9  9  9  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  2 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
/*
 --------------------------->x
|��0��ʼ
|
|
|
|
|
|
|
^y
*/
/*


*/
```
