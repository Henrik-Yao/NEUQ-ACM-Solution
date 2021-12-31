#include <iostream>
#include <vector>
using namespace std;
vector<int> pro_bridge[505];
int reasonway[505];
int flag=1;
int reasoning(int now){
	if(reasonway[now]==0){
		for(int i=0;i<pro_bridge[now].size();i++){
			int next=pro_bridge[now][i];
			if(reasonway[next]==0) reasoning(next);
			reasonway[now]+=reasonway[next];
		}
		if(reasonway[now]==0) flag=0;
	}
	return reasonway[now];
}
int main(){
	int n,m;
	cin >> n >> m;
	int logic1,logic2;
	for(int abs=1;abs<=m;abs++){
		cin >> logic1 >> logic2;
		pro_bridge[logic1].push_back(logic2);
	}
	int A,B;
	cin >> A >> B;
	reasonway[B]=1;
	reasoning(A);
	if(flag==1) cout << reasonway[A] << " Yes" << endl;
	else cout << reasonway[A] << " No" << endl;
	return 0;
}
//DFS学习题