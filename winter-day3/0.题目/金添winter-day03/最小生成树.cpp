#include <bits/stdc++.h>
using namespace std;
// kruskal 克鲁斯卡尔算法
//求最小生成树
struct edge
{
    int cost;  //权值
    int next;  //终点
    int start; //起始
};
bool cmp(edge a, edge b)
{
    return a.cost < b.cost; //让权值递增
}
int bond[2000]; //并查集数组
int num = 0;
int bond_generate(int n) //判断两个点集合是否连通
{
    if (bond[n] == n)
        return n;
    if (bond[n] != n)
        return bond_generate(bond[n]);
}
int main()
{
    int n, e; // n为1-n个节点，e代表边的个数
    while (cin >> n >> e) //多组输入
    {
        num=0;
        edge Edge[2000];
        for (int i = 0; i < e; i++)
        {
            int remp1,remp2,remp3;
            cin>>remp1>>remp2>>remp3;
            Edge[num].start=remp1;Edge[num].next=remp2;Edge[num].cost=remp3;
            num++;
        }
        for (int i = 1; i <= n; i++)
            bond[i] = i; //数列赋初值
        
        // 开始构建MST
        sort(Edge,Edge+num,cmp);
        int mst=0;int num_mst=0;
        for(int i=0;i<num;i++)
        {
            if(bond_generate(Edge[i].start)!=bond_generate(Edge[i].next))
            {//只要不是同一集合，就合并，将此边加入mst
                mst+=Edge[i].cost;
                bond[bond_generate(Edge[i].start)]=bond[Edge[i].next];
                num_mst++;
            }
            if(num_mst==n-1)
                break;
        }
        int judge=bond_generate(1);
        bool flag=1;
        for(int i=1;i<=n;i++)//判断到底是否可以生成mst
        {
            if(bond_generate(i)!=judge)
            flag=0;
        }//如果mst成功生成，那么其中的所有点必定同属一个集合，对所有点遍历，若有一个点不属于这个集合，则说明mst构造失败
        if(flag)
        cout<<mst<<endl;
        else 
        cout<<"There is no minimum spanning tree."<<endl;
        memset(bond,0,sizeof(bond));
    }

    return 0;
}