#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,w;
vector<pair<int,int> >vec[20010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		vec[u].push_back(make_pair(v,w));
	}
	for(int i=0;i<=n;i++){
		if(vec[i].size()){
			printf("%d:",i);
			sort(vec[i].begin(),vec[i].end());
			for(int j=0;j<vec[i].size();j++){
				printf("(%d,%d,%d)",i,vec[i][j].first,vec[i][j].second);
			}
			printf("\n");
		}
	}
	return 0;
}
