#include <iostream>

using namespace std;

const int N = 109;
bool visG[N], visL[N], vis[N][N];

int e, m;
bool vv = 0;

void fi(int s) {
//	printf("s = %d", s);
	if(s == e) {
		vv = 1; // 如果可以到就标记上 
//		cout << " vv = " << vv;
//		return 1;
	}
	else {
		for (int i = 0; i < m; i++) {
			if(i != s && visG[i] && !visL[i] && vis[s][i]) {  // 不是自己 未被感染 没有来过 可以连通 
				visL[i] = 1;
				fi(i);
//				visL[i] = 0;
			}
		}
	}
//	if(vv) return 1;
//	else return 0;
}

int main (){
	int n, k;
	
	cin >> m >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		visG[a] = 1; //未被感染 
	}
	
	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		vis[a][b] = 1, vis[b][a] = 1;//都标记为联通 
	} 
	int s;
	cin >> s >> e;
	
//	bool ju = fi(s);
	visL[s] = 1;
	for (int i = 0; i < m; i++) {
		if(s != i && visG[i] && vis[s][i]) {  //未被感染 不是自己  可以连通 
			visL[i] = 1;  // 标记i为来过 
			fi(i);
			visL[i] = 0;
		}
	}
	
//	printf("vv = %d", fi(1));
	
	if(!visG[e]) printf("The city %d is not safe!", e);
	else if(vv) {
		printf("The city %d can arrive safely", e);
	}
	else printf("The city %d can not arrive safely", e);
	
	return 0;
}
