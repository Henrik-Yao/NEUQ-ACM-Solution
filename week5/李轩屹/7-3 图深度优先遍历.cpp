#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10; 
bool p[maxn];
int a[maxn][2];
int n,e;
void bfs(int m)
{
	if(p[m]) return ;
	p[m]=1;
	cout<<m<<' ';
	int end=n;
	for(int i=0;i<e;i++)
	{
		if(a[i][0]==m&&!p[a[i][1]]) end=min(a[i][1],end);
	}
	if(end!=n) bfs(end);
}
int main()
{

	cin>>n>>e;
	for(int i=0;i<e;i++) cin>>a[i][0]>>a[i][1];
	bfs(0);
	for(int i=1;i<n;i++) 
	if(!p[i]) {
		bfs(i);
	}
	return 0;
}


