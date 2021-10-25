#include <iostream>
#include <vector>
using namespace std;
int survive[10005];
vector<int> city[10005];
int main(){
	int N,M,r1,r2,K,Np,bc,flag;
	cin >> N >> M;
	for(int i=0;i<=N;i++) survive[i]=1;
	for(int abc=1;abc<=M;abc++){
		cin >> r1 >> r2;
		city[r1].push_back(r2);
		city[r2].push_back(r1);	
	}
	cin >> K;
	for(int abc=1;abc<=K;abc++){
		for(int i=0;i<=N;i++) survive[i]=1;
		cin>>Np;
		for(int defg=1;defg<=Np;defg++){
			cin >> bc;
			survive[bc]=0;	
		}
		flag=1;
		for(int i=1;i<=N;i++){
			if(survive[i]!=0){
				for(int j=0;j<city[i].size();j++){
					if(survive[city[i][j]]==1){
						flag=0;
						break;
					}
				}
			}
			if(flag==0) {cout << "NO" << endl; break;}
		}
		if(flag==1) cout << "YES" << endl;
	}
	return 0;
}
