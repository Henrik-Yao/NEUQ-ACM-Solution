#include<bits/stdc++.h>
using namespace std;
int x,y,z,n,m,k;
vector<pair<int,int> >vec[20010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		vec[x].push_back(make_pair(y,z));
	}
	cin>>k;
	while(k--){
		cin>>x>>y;
		for(int i=0;i<vec[x].size();i++){
			if(vec[x][i].first==y){
				vec[x].erase(vec[x].begin()+i);
				break;
			}
		}
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
