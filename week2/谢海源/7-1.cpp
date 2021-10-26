#include<bits/stdc++.h>
using namespace std;
string s[4];
void dfs(int n,int from,int use,int to)
{
	if(n==1) printf("%s->%s\n",s[from].c_str(),s[to].c_str());
	else 
	{
		dfs(n-1,from,to,use);
		printf("%s->%s\n",s[from].c_str(),s[to].c_str());
		dfs(n-1,use,from,to);
	}
}
int main()
{
	int n;
	cin>>n;
	cin>>s[1]>>s[2]>>s[3];
	dfs(n,1,2,3);
    return 0;
}