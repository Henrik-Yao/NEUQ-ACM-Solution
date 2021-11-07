#include <iostream>
using namespace std;
const int maxn=100;
typedef struct{
	int a[maxn][maxn];
	int vexnum,arcnum;
}AMGraph;

int main(){
	int n;
	AMGraph G;
	cin>>G.vexnum>>n>>G.arcnum;
	int s[maxn];
	for(int i=0;i<n;i++)
        cin>>s[i];
	for(int i=0;i<G.vexnum;i++){
		for(int j=0;j<G.vexnum;j++){
			G.a[i][j]=0;
		}
	}
	for(int i=0;i<G.arcnum;i++){
		int x,y;
		cin>>x>>y;
		G.a[x][y]=1;
		G.a[y][x]=1;
	}
	int B,E,flag=0;
	cin>>B>>E;
	for(int i=0;i<n;i++){
		if(E==s[i]){
			flag=1;
			break;
		}
	}
	if(G.a[B][E]==1){
		if(flag) 
		printf("The city %d can arrive safely!",E);
		else printf("The city %d is not safe!",E);
	}
	else {if(flag) 
		printf("The city %d can not arrive safely!",E);
		else printf("The city %d is not safe!",E);
	}
	
	
	
	
	return 0;
}
