#include<bits/stdc++.h>
using namespace std;

int N,M,A,B;
vector<int>t[520];
int v[520],f[520];//f标记从此处到B点的总路径数，v标记是否被访问过 

int dfs(int x)
{
    v[x]=1;
    if(f[x]) return f[x];//已经到终点，递归结束 
    for(auto y:t[x])
    {
    	f[x]+=dfs(y);
	}//遍历当前点处的分支，将分支可到达B点的路径条数加到当前点上 
    return f[x];
}
int main()
{
	cin>>N>>M;
	int i;
	while(M--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		t[a].push_back(b);//b为a的分支 
	}
	cin>>A>>B;
	f[B]=1;//标记终点，为dfs中递归函数终止条件 
	cout<<dfs(A)<<" ";
    int flag=1;
    for(i=1;i<=N;++i)
        if(!f[i]&&v[i])//如果某点从A处可以访问到但是没有路径到达B ，则不是逻辑自洽的 
			flag=0;
	if(flag)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}
