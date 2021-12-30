/* 
7-6 森森旅游
好久没出去旅游啦！森森决定去 Z 省旅游一下。
Z 省有 n 座城市（从 1 到 n 编号）以及 m 条连接两座城市的有向旅行线路
（例如自驾、长途汽车、火车、飞机、轮船等），每次经过一条旅行线路时都需要支付该线路的费用
（但这个收费标准可能不止一种，例如车票跟机票一般不是一个价格）。
Z 省为了鼓励大家在省内多逛逛，推出了旅游金计划：在 i 号城市可以用 1 元现金兑换 ai元旅游金
（只要现金足够，可以无限次兑换）。城市间的交通即可以使用现金支付路费，也可以用旅游金支付。
具体来说，当通过第 j 条旅行线路时，可以用 cj元现金或 dj元旅游金支付路费。
注意： 每次只能选择一种支付方式，不可同时使用现金和旅游金混合支付。
但对于不同的线路，旅客可以自由选择不同的支付方式。
森森决定从 1 号城市出发，到 n 号城市去。他打算在出发前准备一些现金，
并在途中的某个城市将剩余现金 全部 换成旅游金后继续旅游，直到到达 n 号城市为止。
当然，他也可以选择在 1 号城市就兑换旅游金，或全部使用现金完成旅程。
Z 省政府会根据每个城市参与活动的情况调整汇率（即调整在某个城市 1 元现金能换多少旅游金）。
现在你需要帮助森森计算一下，在每次调整之后最少需要携带多少现金才能完成他的旅程。
输入格式:
输入在第一行给出三个整数 n，m 与 q（1≤n≤10^5,1≤m≤2×10^5,1≤q≤10^5），
依次表示城市的数量、旅行线路的数量以及汇率调整的次数。
接下来 m 行，每行给出四个整数 u，v，c 与 d（1≤u,v≤n，1≤c,d≤10^9），
表示一条从 u 号城市通向 v 号城市的有向旅行线路。
每次通过该线路需要支付 c 元现金或 d 元旅游金。数字间以空格分隔。
输入保证从 1 号城市出发，一定可以通过若干条线路到达 n 号城市，
但两城市间的旅行线路可能不止一条，对应不同的收费标准；
也允许在城市内部游玩（即 u 和 v 相同）。
接下来的一行输入 n 个整数 a1,a2,……,an（1≤ai≤10^9），
其中 ai表示一开始在 i 号城市能用 1 元现金兑换 ai个旅游金。数字间以空格分隔。
接下来 q 行描述汇率的调整。第 i 行输入两个整数 xi与a'i（1≤xi≤n，1≤a'i≤10^9），
表示第 i 次汇率调整后，xi号城市能用 1 元现金兑换a'i个旅游金，而其它城市旅游金汇率不变。
请注意：每次汇率调整都是在上一次汇率调整的基础上进行的。
输出格式:
对每一次汇率调整，在对应的一行中输出调整后森森至少需要准备多少现金，
才能按他的计划从 1 号城市旅行到 n 号城市。
再次提醒：如果森森决定在途中的某个城市兑换旅游金，那么他必须将剩余现金全部、一次性兑换，
剩下的旅途将完全使用旅游金支付。
输入样例:
6 11 3
1 2 3 5
1 3 8 4
2 4 4 6
3 1 8 6
1 3 10 8
2 3 2 8
3 4 5 3
3 5 10 7
3 3 2 3
4 6 10 12
5 6 10 6
3 4 5 2 5 100
1 2
2 1
1 17
输出样例:
8
8
1
样例解释:
对于第一次汇率调整，森森可以沿着 1→2→4→6 的线路旅行，并在 2 号城市兑换旅游金；
对于第二次汇率调整，森森可以沿着 1→2→3→4→6 的线路旅行，并在 3 号城市兑换旅游金；
对于第三次汇率调整，森森可以沿着 1→3→5→6 的线路旅行，并在 1 号城市兑换旅游金。
*/
#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;
struct node{
	int id;
	long long dis;
	friend bool operator< (const node &a, const node &b);
};
bool operator< (const node &a, const node &b){
	return a.dis>b.dis;
}
int flags=0,n,m,q,u,v,xi,visit1[100005],visit2[100005];
long long c,d,w,ai,huan[100005],cash1[100005],vou1[100005],tran[100005];
vector<pair<int,long long> > cash2[100005],vou2[100005];
multiset<long long> minCost;
priority_queue<node> q;
void Dijskra (int s,vector<pair<int,long long> > E[],long long dis[],int visit[]){
	fill(dis+1,dis+n+1,INF);
	dis[s]=0;
	node a;a.id=s;dis=0;
	q.push(a);
	while(!q.empty()){
		int now=q.top().id;
		q.pop();
		if(visit[now]) continue;
		visit[now]=1;
		for(int i=0;i<(int)E[now].size();i++){
			v=E[now][i].first;
			w=E[now][i].second;
			if(dis[v]>dis[now]+w){
				dis[v]=dis[now]+w;
				q.push(node{v,dis[v]});
			}
		}
	} 
}
int main(){
	freopen("in6.txt","r",stdin); 
    ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		cin>>u>>v>>c>>d;
		node x1,x2;
		x1.id=v;x1.dis=c;
		x2.id=u;x2.dis=v;
		cash2[u].push_back(x1);
		vou2[v].push_back(x2);
	}
	for(int i=1;i<=n;i++) cin>>huan[i];
	Dijskra(1,cash2,cash1,visit1);
	Dijskra(n,vou2,vou1,visit2);
	for(int i=1;i<=n;i++) {
		if (cash1[i]==INF || vou1[i]==INF) continue;
		minCost.insert(tran[i]=cash1[i]+(vou1[i]+huan[i]-1)/huan[i]);
	}
	for(int i=0;i<q;i++){
		cin>>xi>>ai;
		if(!tran[xi] || huan[xi]==ai)
			if(flags) cout<<endl<<*minCost.begin();
			else{
				cout<<*minCost.begin();
				flags=1;
			}
		else{
			minCost.erase(minCost.find(tran[xi]));
			huan[xi]=ai;
			minCost.insert(tran[xi]=cash1[xi]+(vou1[xi]+huan[xi]-1)/huan[xi]);
			if(flags) cout<<endl<<*minCost.begin();
			else{
				cout<<*minCost.begin();
				flags=1;
			}
		}
	}
}
