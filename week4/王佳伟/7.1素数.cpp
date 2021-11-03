#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int prime[maxn];
int visit[maxn];
int main() {
	
	memset(prime, 0, sizeof(prime));
	memset(visit, 0, sizeof(visit));
	int cnt = 1;//素数的个数 
	for(int i = 2; i <= 100001; i++){
		if(!visit[i]){//如果是素数 
			prime[cnt++] = i;//记录此素数 
		}
		for(int j = 1; j <= cnt && i * prime[j] <= 100001; j++){//枚举所有素数与i相乘 
			visit[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;//减少冗余计算 
		}
	}
	
    int a, b;
    while(cin >> a >> b){
        for(int i = 1; i <= 100001; i++){
		    if(prime[i] >= a && prime[i] <= b){
                cout << prime[i];
                if(prime[i+1] > b){
                    cout << endl;
                    break;
                }
                else{
                    cout << " ";
                }
            }
        }
	}
}
