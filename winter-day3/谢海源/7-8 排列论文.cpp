#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
//dfs实现,从出度的角度来构造,递归到最后返回
int n,m;
bool v2[maxn];
vector<int>t2[maxn];

vector<int>t[maxn];  //i点的邻接表,即i与哪些点相连
int ans[maxn],cnt;    //排序结果数组,cnt记录个数
int parent[maxn]; //记录其前置节点
//int d[N], Time, f[N]; //可以不要,时间time初始化为0，d[]记录第一次被发现时，f[]记录结束检查时
int vis[maxn];  //标记数组vis[i]=0表示还未访问过点i,c[i]=1表示已经访问过点i，并且还递归访问过它的所有子孙，c[i]=-1表示正在访问中，尚未返回
 
bool dfs(int s)  //深度优先搜索（邻接表实现），记录时间戳，寻找最短路径
{
    vis[s]=-1;   //正在访问
    //Time++;d[s]=Time;
    int len = t[s].size();
    for(int i=0;i<len;i++)
    {
        int tmp=t[s][i];
        if(vis[tmp]<0) //如果子孙比父亲先访问，说明存在有向环，失败退出
            return false;
        else if(!vis[tmp]&&!dfs(tmp)) //如果子孙未被访问，访问子孙返回假，说明也是失败
            return false;
        parent[tmp]=s;
    }
    vis[s]=1;
    //Time++;f[s]=Time;
    ans[cnt++]=s;  //结果是逆序的,递归的原因
    return true;
}
 
bool topSort()    //返回值代表是否有环,排序结果在ans数组
{
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        vis[i]=0;
    }
    //Time=0;
    for(int i=1;i<=n;i++)
        if(!vis[i])
            if(dfs(i)==false)
                return false;
    return true;
}
bool check()
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(v2[i]) continue;//
		sum++;
		if(sum>1) return 0;
	}
	return 1;
}
int main()
{
	while(cin>>n>>m)
	{
		memset(v2,0,sizeof(v2));
		for(int i=1;i<=n;i++) t[i].clear();
		int d,u;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&d,&u);
			t[d].push_back(u);//d指向u
			t2[u].push_back(d);//u指向d
			v2[u]=1;//标记为子孙
		}
		if(topSort())
		{
			if(check())cout<<"1"<<endl;//无前溯的点只有一个则只有一种排序
			else cout<<"2"<<endl;
		}
		else cout<<"0"<<endl;
	}
    return 0;
}
