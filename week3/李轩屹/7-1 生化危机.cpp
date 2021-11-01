#include <bits/stdc++.h>
using namespace std;
int Safe[101],arcs[101][101],vis[101];
int main(){
	int m,n,k;
	int s,d;
	cin>>m>>n>>k;
	while(n--){
		int safe;
		cin>>safe;
		Safe[safe]=1;
	}
	while(k--){
		int i,j;
		cin>>i>>j;
		arcs[i][j]=1;
		arcs[j][i]=1;
	}
	cin>>s>>d;
	if(Safe[d]==0) cout<<"The city "<<d<<" is not safe!";
	else{
		bool p=0;
		for(int i=0;i<m;i++){
			if(arcs[s][i]==1&&Safe[i]==1){
				s=i,i=0;
				if(s==d){
					p=1;
					break;
				}
			}
		}
		if(p) cout<<"The city "<<d<<" can arrive safely!";
		else cout<<"The city "<<d<<" can not arrive safely!";
	}
	return 0;
}



