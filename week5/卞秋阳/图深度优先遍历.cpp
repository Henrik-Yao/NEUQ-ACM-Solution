#include<bits/stdc++.h>
using namespace std;
vector<int>infer[20010];
bool c[20010]={};
void dfs(int n);
int main()
{  int a,b,n,e;
   cin>>n>>e;
	while(e--){
		scanf("%d %d",&a,&b);
		infer[a].push_back(b);}
	  for(int i=0;i<n;i++){
		if(c[i]==0) dfs(i);
	}
    return 0;
}
void dfs(int n)
{
	int k;
    cout<<n<<" ";c[n]=1;
	sort(infer[n].begin(),infer[n].end());
	for(auto k:infer[n]){
		if(c[k]==0) dfs(k);
	}
}
