/*
7-8 排列论文
给定编号为1至n的n篇论文，以及m个形如d, u (1≤d,u≤n,d!=u)的引用关系，
表示论文论文d中定义的一个名词在论文u中被引用。现在要对这n篇论文重新排列，
排列方案须满足如下要求：一篇论文引用的名词必须在排在他前面的论文中被定义过。
请编写程序粗略计算都有多少种满足要求的方案，如果无满足要求的方案则输出0，
如果有唯一方案则输出1，如果有多种方案则输出2。
输入格式:
输入包含多组数据，每组数据第一行为两个正整数n和m，分别表示论文篇数和引用关系数，
均不超过100。接下来m行表示论文引用关系，每行为空格间隔的2个正整数d和u，
表示论文论文d中定义的一个名词在论文u中被引用。
输出格式:
对于每组数据输出一个整数：无满足要求的排列方案则输出0，如果有唯一方案则输出1，
如果有多种方案则输出2。
输入样例:
5 4
1 5
5 2
3 2
4 3
5 4
3 1
4 2
1 5
5 4
输出样例:
2
1
*/
#include <bits/stdc++.h>
using namespace std;
int d,u,n,m,x[128];
vector<int>edge[128],ans;
queue<int>q;
int main(){
	freopen("in8.txt","r",stdin);
    while(cin>>n>>m){
    	if(n==EOF) break;
        int flag=0,cnt=0;
        for(int i=0;i<m;i++){
            cin>>d>>u;
            edge[d].push_back(u);
            x[u]++;
        }
        for(int i=1;i<=n;i++){
            if(!x[i]){
                q.push(i);
                cnt++;
            }
        }
        if(cnt>1) flag=1;
        while(!q.empty()){
            int p=q.front();q.pop();
            ans.push_back(p);
            for(int i=0;i<edge[p].size();i++){
                int y=edge[p][i];
                x[y]--;
                if(!in[y]) q.push(y);
            }
        }
        if(ans.size()==n){
            if(!flag) cout<<"1"<<endl;
            else cout<<"2"<<endl;
        }
        else cout<<"0"<<endl;
        for(int i=0;i<m;i++) edge[i].clear();
        ans.clear();
		while(!q.empty())q.pop();
		memset(x,0,sizeof(x));
    }
}
