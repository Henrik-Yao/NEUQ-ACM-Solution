#include<bits/stdc++.h>
using namespace std;

#define maxn 100001
int prime[maxn];
bool visit[maxn];
int main() {
	
	memset(prime, 0, sizeof(prime));
	memset(visit, 0, sizeof(visit));
	int cnt = 0;//�����ĸ��� 
	for(int i = 2; i <= maxn; i++){
		if(!visit[i]){//��������� 
			prime[++cnt] = i;//��¼������ 
		}
		for(int j = 1; j <= cnt && i * prime[j] <= maxn; j++){//ö������������i��� 
			visit[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;//����������� 
		}
	}
	
	int n;
	long long t;
	cin >> n;
	while(n--){
		cin >> t;
		if(t % 2 == 0){
			cout << 2 << endl;
			continue;
		}
		int s = sqrt(t);
		bool flag = true;
		bool sign = true;//t-2������ 
		for(int i = 1; i <= cnt; i++){
//			int now = prime[i];
			if(prime[i] > s || (!flag && !sign)){
//				cout << 1 << endl;
				break;
			}
			if(t % prime[i] == 0){
				flag = false;
//				if(sign){
//					cout << "kkk" << prime[i] << endl;
//					cout << 2 << endl;
//				}
//				else{
//					cout << 3 << endl;
//				}
//				break;
			}
			if(sign && (t-2) % prime[i] == 0){
//				cout << "hhh" << prime[i] << endl;
				sign = false;
			}
		}
		if(flag){//������ 
			cout << 1 << endl;
		}
		else{//�������� 
			if(sign){//t-2������ 
				cout << 2 << endl;
			}
			else cout << 3 << endl;
		}
	}
//	cout << cnt;
//	for(int i = 1; i < cnt; i++){
//		cout << prime[i] << " ";
//	}
//cout << prime[cnt];
	
	
}

