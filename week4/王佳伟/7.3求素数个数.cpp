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
	int cnt = 0;//�����ĸ��� 
	for(int i = 2; i <= n; i++){
		if(!visit[i]){//��������� 
			prime[++cnt] = i;//��¼������ 
		}
		for(int j = 1; j <= cnt && i * prime[j] <= n; j++){//ö������������i��� 
			visit[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;//����������� 
		}
	}
	cout << cnt << endl;

}
