#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int pre[105][105];
ll tu[105][105];
int v,e;
ll dis[105][105];
bool jud[105];
void dfs(int m,int n) {
	if(m==n) {
		cout<<n;
		return ;
	}
	dfs(m,pre[m][n]);
	cout<<"->"<<n;
}
int main() {
	cin>>v>>e;
	memset(tu,0x3f3f3f3f3f3f,sizeof(tu));
	while(e--) {
		int a,b,c;
		cin>>a>>b>>c;
		tu[a][b]=c;
	}
	int m,n;
	int x,y;
	ll max=0;
	for (m=0;m<v;m++) {
		for (int i=0;i<v;i++) {
			dis[m][i]=0x3f3f3f3f3f3f;
			pre[m][i]=i;
			jud[i]=0;
		}
		int count;
		dis[m][m]=0;
		for (int t=0;t<v;t++) {
			ll minn=0x3f3f3f3f3f3f;
			count = -1;
			for (int i=0;i<v;i++)
						if(dis[m][i]<=minn&&!jud[i]) {
				minn=dis[m][i];
				count=i;
			}
			jud[count]=1;
			for (int i=0;i<v;i++)
					if(tu[count][i]+dis[m][count]<dis[m][i]&&!jud[i]) {
				dis[m][i]=tu[count][i]+dis[m][count];
				pre[m][i] = count ;
			}
		}
		for (int i=0;i<v;i++)
			if(dis[m][i]>max&&dis[m][i]<0x3f3f3f3f3f3f) {
			max=dis[m][i];
			x=m;
			y=i;
		}
	}
	cin>>m>>n;
    if(m==n) cout<<n<<"->"<<n<<":"<<0;
	else if(dis[m][n]<0x3f3f3f3f3f3f) {
		dfs(m,n);
		cout<<":"<<dis[m][n];
	} else cout<<m<<"->"<<n<<":"<<-1;
	cout<<'\n';
	cin>>m>>n;
	if(m==n) cout<<n<<"->"<<n<<":"<<0;
	else if(dis[m][n]<0x3f3f3f3f3f3f) {
		dfs(m,n);
		cout<<":"<<dis[m][n];
	} else cout<<m<<"->"<<n<<":"<<-1;
	cout<<'\n';
	dfs(x,y);
	cout<<":"<<dis[x][y];
	return 0;
}
