#include<bits/stdc++.h>
using namespace std;
#define MOD 1000007

//dp[i][k]ǰi�����j��Ϊֹ���Ļ�μ��� 
//dp[i][j] = dp

int main() {
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		vector<int> dp(n+1, 0);
		vector<vector<int>> a(n+1, vector<int>(2));
		for(int i = 1; i <= n; i++){
			cin >> a[i][0] >> a[i][1];
		}
		sort(a.begin()+1, a.end());
		
		int now = a[1][1];
		int res = 1;
		for(int i = 1; i <= n; i++){
			if(a[i][1] < now){
				now = a[i][1];
				continue;
			}
			if(a[i][0] >= now){
				now = a[i][1];
				res++;
			}
		} 
		cout << n-res << endl;
//		for(int i = 1; i <= n; i++){
//			if(a[i][1] < a[i][0]){
//				
//			}
//			if(a[i][0] >= dp[i-1]){
//				if(a[i][0] > a[i][1] && a[i][1] > dp[1]){
//					cout << "kkk";
//					continue;
//				}
//				res++;
//				dp[i] = a[i][1];
//			}
//			else{
//				if(dp[i-1] > a[i][1])
//				dp[i-1] = min();
//			}
//		}
//		cout << n-res << endl;
	}
}

/*
3 5 
4 6
7 10
23 4�����״̬��ǰ���״̬�йأ�3 5������4 6. ������ѡ3 5���ã���Ϊ5��С������������������4��3�ã����ö��壺���dpΪ����ѡ��i��

dp[i][j]����ǰi�������ʱ��Ϊj,�������Ҳ�ǲ��е�,��a[i][0],a[i][1]Ϊһ���Ƚ�С��������Ӱ�쵽�ϴ�ġ�����ѡ���a[i][0]��С�������� 

dp[i][j]�����Ϊi����ǰj�����ѡ�� 


*/


/*
2
5
1 4
3 5
3 8
5 9
12 14
5
2 3
3 10
8 9
9 15
4 10
*/
