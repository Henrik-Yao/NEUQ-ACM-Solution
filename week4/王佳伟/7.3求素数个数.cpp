#include<bits/stdc++.h>
using namespace std;
#define maxn 10000001
int prime[1000000];
bool visit[maxn];
int main() {
	int n;
	cin >> n;
	memset(prime, 0, sizeof(prime));
	memset(visit, 0, sizeof(visit));
	int cnt = 0;//素数的个数 
	for(int i = 2; i <= n; i++){
		if(!visit[i]){//如果是素数 
			prime[++cnt] = i;//记录此素数 
		}
		for(int j = 1; j <= cnt && i * prime[j] <= n; j++){//枚举所有素数与i相乘 
			visit[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;//减少冗余计算 
		}
	}
	cout << cnt << endl;

}
