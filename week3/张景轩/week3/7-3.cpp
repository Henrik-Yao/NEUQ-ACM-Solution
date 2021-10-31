#include<iostream>
#include<cstring>
using namespace std;

int n, m, k, l;//n行m列 
int open = 0; // 开了open个方格 
int bo[22][22];//没开-1， 有雷-2， 已打开周围无雷0， 有雷x  
bool book[22][22] = {false};
int lr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int ud[8] = {1, 0, -1, -1, -1, 0, 1, 1};

void dfs(int x, int y){
	if(book[x][y] || x < 0 || x >= n || y < 0 || y >= m){
		return;
	}
	book[x][y] = true;
	open++;
	int risk = 0;
	for(int i = 0; i < 8; i++){
		int f = x+ud[i];
		int s = y+lr[i];
		if(f >= 0 && f < n && s >= 0 && s < m && bo[f][s] == -2) risk++;
	} 

	if(risk == 0){//周围全部深度搜索 
		bo[x][y] = 0;
		for(int i = 0; i < 8; i++){
			dfs(x+ud[i], y+lr[i]);
		}
	}
	else{
		bo[x][y] = risk;
		return;
	}
}


int main() {
	
	cin >> n >> m >> k >> l;
	int num = n*m-k;
	memset(bo, -1, sizeof(bo));//初始化 
	int x, y;
	for(int i = 0; i < k; i++)
    {
		cin >> x >> y;
		bo[x][y] = -2;
	} 
	
	//操作 
	for(int k = 0; k < l; k++){
		cin >> x >> y;
		if(bo[x][y] == -2){
			cout << "You lose";
			return 0;
		}
		if(bo[x][y] != -1) 
        {
            continue;
        }
        dfs(x, y);
		for(int i = 0; i < n; i++)
        {
			for(int j = 0; j < m; j++)
            {
				if(bo[i][j] == -2) cout << -1 << " ";
				else cout << bo[i][j] << " ";
			}
			cout << "\n";
		}
		if(open == num)
        {
			cout << "You win" << "\n";
			return 0;
		} 
		cout << "\n";
	} 

}

//点击方格后分析周围8个格雷的数量，若没有则继续打开方格。无法选中条件为越界，周围有雷，已搜索