#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct person{
	string ming;
	int gender;
}p[200010];
int fa[200010];
map<string,int>mp;
bool check(int a,int b){
	int i=1,j;
	for (int x=a;x!=0;x=fa[x],i++){
		j=1;
		for (int y=b;y!=0;y=fa[y],j++){
			if (i>=5&&j>=5) break;
			if (x==y&&(i<5||j<5)) return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n;
	string xing,temp;
	for (int i=1;i<=n;i++){
		cin>>p[i].ming>>xing;
		mp[p[i].ming]=i;
		int len=xing.length();
		if (xing[len-1]=='m') p[i].gender=1;
		else if (xing[len-1]=='f') p[i].gender=0;	
		else if (xing[len-1]=='n') p[i].gender=1,fa[i]=mp[xing.substr(0,len-4)];
		else p[i].gender=0,fa[i]=mp[xing.substr(0,len-7)];
	}
	cin>>m;
	string xing1,ming1,xing2,ming2;
	for (int i=1;i<=m;i++){
		cin>>ming1>>xing1>>ming2>>xing2;
		if (mp.find(ming1)==mp.end()||mp.find(ming2)==mp.end()){
			cout<<"NA"<<endl;
			continue;
		}
		int id1=mp[ming1];
		int id2=mp[ming2];
		if (p[id1].gender==p[id2].gender){
			cout<<"Whatever"<<endl;
			continue;
		}		
		if (check(id1,id2)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
