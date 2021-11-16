#include <bits/stdc++.h>
using namespace std;
int sex[300010],vis[300010],id,flag;
int fa,mo,qry1,qry2;
char gender;
vector<int> g[300010];
int xx[10001],yy[10001],cntx=0,cnty=0;
int change(string str){
	int id=0;
	if (str[0]=='-') return -1;
	for (int i=0;i<str.length();i++){
		id=id*10+str[i]-'0';
	}
	return id;
}
void dfs1(int p,int cnt){
	if (cnt>=5) return;
	if (g[p].size()==0) return;
	for (int i=0;i<g[p].size();i++){
		int to=g[p][i];
		if (!vis[to]){
			vis[to]=1;
			xx[++cntx]=to;
			dfs1(to,cnt++);
		}
	}
}
void dfs2(int p,int cnt){
	if (cnt>=5) return;
	if (g[p].size()==0) return;
	for (int i=0;i<g[p].size();i++){
		int to=g[p][i];
		if (!vis[to]){
			vis[to]=1;
			yy[++cnty]=to;
			dfs2(to,cnt++);
		}
	}
}
int main() {
	int n,k;
	string name;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>name>>gender;
		id=change(name);
		if (gender=='M') sex[id]=1;
		else sex[id]=0;
		cin>>name;
		fa=change(name);
		sex[fa]=1;
		if (fa!=-1) g[id].push_back(fa);
		cin>>name;
		mo=change(name);
		sex[mo]=0;
		if (mo!=-1) g[id].push_back(mo);
	}
	cin>>k;
	for (int i=1;i<=k;i++){
		cin>>name;
		qry1=change(name);
		cin>>name;
		qry2=change(name);
		if (sex[qry1]==sex[qry2]) {
			cout<<"Never Mind"<<endl;
		}
		else {
			flag=1;
			cntx=0,cnty=0;
			memset(vis,0,sizeof vis);
			dfs1(qry1,1);
			memset(vis,0,sizeof vis);
			dfs2(qry2,1);
			for (int i=1;i<=cntx;i++)
				for (int j=1;j<=cnty;j++)
					if (xx[i]==yy[j]) flag=0;
			if (flag) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
