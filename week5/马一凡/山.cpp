#include<iostream>
using namespace std;

int mp[2100][2100];
bool vs[2100][2100];
int n, m,sum=0;

void dfs(int x, int y){
	if(x<0 || x>=n || y<0 || y>=m || vs[x][y] || mp[x][y] == 0){
		return;
	}
	vs[x][y] = true;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
        for(int t=0; t<m; t++){
            scanf("%d",&mp[i][t]);
        }
	}
	for(int j=0; j<n; j++){
		for(int k=0; k<m; k++){
			if(!vs[j][k] && mp[j][k] == 1){
				dfs(j,k);
				sum++;
			}
		}
	}
	printf("%d",sum);
	
	
	return 0;
}
