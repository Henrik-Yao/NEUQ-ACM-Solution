#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> num[20005];
vector<int> leaves;
int vis[20005];
void dfs(int n){
	if(vis[n]==1) return;
	if(vis[n]==0){vis[n]=1;leaves.push_back(n);}
//	cout << "P Search at "<< n << endl; 
    if(num[n].size()==0) return;
    else{
    	for(int i=0;i<num[n].size();i++){
    		for(int j=0;j<num[n].size()-1;j++){
    			if(num[n][j]>num[n][j+1]) swap(num[n][j],num[n][j+1]);
			}
		}
        for(int i=0;i<num[n].size();i++){
        	dfs(num[n][i]);
        }
    }
}
int main(){
    int n,e;
    cin >> n >> e;
    int e1,e2;
    for(int abs=0;abs<e;abs++){
        cin >> e1 >> e2;
    //    if(e1>e2) swap(e1,e2);
        num[e1].push_back(e2);
    }
    for(int i=0;i<n;i++){
		dfs(i);
	}
    leaves[0]=0;;
    bool first=true;
    int op;
    for(int i=0;i<leaves.size();i++) cout << leaves[i] << " ";
    return 0;
}