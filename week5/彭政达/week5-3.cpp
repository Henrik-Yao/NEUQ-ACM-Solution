#include<bits/stdc++.h>
using namespace std;
#define file_in freopen("in.txt","r",stdin)
#define file_out freopen("out.txt","w",stdout)
vector<int> a[20010];
int visited[20010]; 
int n,m,sum;
void ddfs(int x){
	int i;
	cout<<x<<" ";
	visited[x]=1;
	int len=a[cur].size();
	for(int i=0;i<len;i++)
		if (visited[a[x][i]]==0)
			ddfs(a[x][i]);
}
int main(){
	int di,dj;
    ios::sync_with_stdio(false);
    file_in;
	file_out; 
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>di>>dj;
		a[di].push_back(dj);
	}
	for(int i=0;i<n;i++)
		sort(a[i].begin(),a[i].end());
	for(int i=0;i<n;i++)
		if(visited[i]==0)
			ddfs(i);
	return 0; 
}
