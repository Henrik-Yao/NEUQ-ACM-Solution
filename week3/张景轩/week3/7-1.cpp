#include <iostream>
#include<vector>
#include<queue>
using namespace std;

#define ll long long

const int _=1e5+7;
int read() {
    int x=0;
    int flag = 1;
    char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) 
    {
        if(s=='-') flag=-1;
    }
    for(;s>='0'&&s<='9';s=getchar()) 
    {
        x=x*10 + s-'0';
    }
    return x*flag;
}

int n,m,k,visit[_],ok[_];
vector<int> v[_];

int main() {
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;++i) 
    {
        visit[read()+1]=1;
    }
    for(int i=1;i<=k;++i) 
    {
        int x=read()+1,y=read()+1;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int s=read()+1,d=read()+1;
    if(!visit[d]) {
        cout<<"The city "<<d-1<<" is not safe!";
        return 0;
    }

    queue<int> q;

    q.push(s);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        ok[u]=1;
        for(auto v:v[u]) {
            if(!ok[v]) q.push(v);
        }
    }
    if(!ok[d]) 
    {
        cout<<"The city "<<d-1<<" can not arrive safely!";
        
    }
    else 
    {
        cout<<"The city "<<d-1<<" can arrive safely!";
    }
    return 0;
}

/*
广度优先搜索算法。借助队列实现通过一定的方式来维护队列的单调递增，那么，队头元素一定是深度最小的
从顶点开始访问，然后访问邻接结点
循环遍历
*/