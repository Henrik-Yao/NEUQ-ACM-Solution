#include<bits/stdc++.h>
using namespace std;

int N,M,A,B;
vector<int>t[520];
int v[520],f[520];

int dfs(int x)
{
    v[x]=1;
    if(f[x]) return f[x];
    for(auto y:t[x])
    {
    	f[x]+=dfs(y);
	} 
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
		t[a].push_back(b);
	}
	cin>>A>>B;
	f[B]=1;
	cout<<dfs(A)<<" ";
    int flag=1;
    for(i=1;i<=N;++i)
        if(!f[i]&&v[i])
			flag=0;
	if(flag)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}
