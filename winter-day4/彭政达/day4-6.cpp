/* 
7-6 ɭɭ����
�þ�û��ȥ��������ɭɭ����ȥ Z ʡ����һ�¡�
Z ʡ�� n �����У��� 1 �� n ��ţ��Լ� m �������������е�����������·
�������Լݡ���;�������𳵡��ɻ����ִ��ȣ���ÿ�ξ���һ��������·ʱ����Ҫ֧������·�ķ���
��������շѱ�׼���ܲ�ֹһ�֣����糵Ʊ����Ʊһ�㲻��һ���۸񣩡�
Z ʡΪ�˹��������ʡ�ڶ��䣬�Ƴ������ν�ƻ����� i �ų��п����� 1 Ԫ�ֽ�һ� aiԪ���ν�
��ֻҪ�ֽ��㹻���������޴ζһ��������м�Ľ�ͨ������ʹ���ֽ�֧��·�ѣ�Ҳ���������ν�֧����
������˵����ͨ���� j ��������·ʱ�������� cjԪ�ֽ�� djԪ���ν�֧��·�ѡ�
ע�⣺ ÿ��ֻ��ѡ��һ��֧����ʽ������ͬʱʹ���ֽ�����ν���֧����
�����ڲ�ͬ����·���ÿͿ�������ѡ��ͬ��֧����ʽ��
ɭɭ������ 1 �ų��г������� n �ų���ȥ���������ڳ���ǰ׼��һЩ�ֽ�
����;�е�ĳ�����н�ʣ���ֽ� ȫ�� �������ν��������Σ�ֱ������ n �ų���Ϊֹ��
��Ȼ����Ҳ����ѡ���� 1 �ų��оͶһ����ν𣬻�ȫ��ʹ���ֽ�����ó̡�
Z ʡ���������ÿ�����в���������������ʣ���������ĳ������ 1 Ԫ�ֽ��ܻ��������ν𣩡�
��������Ҫ����ɭɭ����һ�£���ÿ�ε���֮��������ҪЯ�������ֽ������������ó̡�
�����ʽ:
�����ڵ�һ�и����������� n��m �� q��1��n��10^5,1��m��2��10^5,1��q��10^5����
���α�ʾ���е�������������·�������Լ����ʵ����Ĵ�����
������ m �У�ÿ�и����ĸ����� u��v��c �� d��1��u,v��n��1��c,d��10^9����
��ʾһ���� u �ų���ͨ�� v �ų��е�����������·��
ÿ��ͨ������·��Ҫ֧�� c Ԫ�ֽ�� d Ԫ���ν����ּ��Կո�ָ���
���뱣֤�� 1 �ų��г�����һ������ͨ����������·���� n �ų��У�
�������м��������·���ܲ�ֹһ������Ӧ��ͬ���շѱ�׼��
Ҳ�����ڳ����ڲ����棨�� u �� v ��ͬ����
��������һ������ n ������ a1,a2,����,an��1��ai��10^9����
���� ai��ʾһ��ʼ�� i �ų������� 1 Ԫ�ֽ�һ� ai�����ν����ּ��Կո�ָ���
������ q ���������ʵĵ������� i �������������� xi��a'i��1��xi��n��1��a'i��10^9����
��ʾ�� i �λ��ʵ�����xi�ų������� 1 Ԫ�ֽ�һ�a'i�����ν𣬶������������ν���ʲ��䡣
��ע�⣺ÿ�λ��ʵ�����������һ�λ��ʵ����Ļ����Ͻ��еġ�
�����ʽ:
��ÿһ�λ��ʵ������ڶ�Ӧ��һ�������������ɭɭ������Ҫ׼�������ֽ�
���ܰ����ļƻ��� 1 �ų������е� n �ų��С�
�ٴ����ѣ����ɭɭ������;�е�ĳ�����жһ����ν���ô�����뽫ʣ���ֽ�ȫ����һ���Զһ���
ʣ�µ���;����ȫʹ�����ν�֧����
��������:
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
�������:
8
8
1
��������:
���ڵ�һ�λ��ʵ�����ɭɭ�������� 1��2��4��6 ����·���У����� 2 �ų��жһ����ν�
���ڵڶ��λ��ʵ�����ɭɭ�������� 1��2��3��4��6 ����·���У����� 3 �ų��жһ����ν�
���ڵ����λ��ʵ�����ɭɭ�������� 1��3��5��6 ����·���У����� 1 �ų��жһ����ν�
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
