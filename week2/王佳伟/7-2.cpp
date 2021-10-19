#include<bits/stdc++.h>
using namespace std;

struct connect{ //连接 
	int city1;
	int city2;
}con[10001];;


int main() {
	int n, m; 
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> con[i].city1 >> con[i].city2;
	}
	int t;//方案数 
	int k; 
	int c;//除去编号为c的城市 
	int insist[10001] = {0};//第i编号的城市是否存在 ,0代表存在，1代表不存在 
	cin >> t;
	for(int i = 0; i < t; i++){
		memset(insist, 0, sizeof(insist));
		cin >> k;
		for(int i = 0; i < k; i++){
			cin >> c;
			insist[c] = 1;
		}
		//判断是否可行
		bool judge = true;
		for(int j = 0; j < m; j++){ //看还有哪个连接不满足要求 
			if(!insist[con[j].city1] && !insist[con[j].city2]) {//都存在 
				judge = false;
			}
		} 
		if(judge){
			cout << "YES" << endl; 
		}
		else cout << "NO" << endl;
	}
	

	
}
