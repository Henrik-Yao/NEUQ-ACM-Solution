#include <iostream>
#include <cstring>
using namespace std;
#define inf 999999
int main(){
	int city,road;
	while(cin>>city>>road){
		int dp[city][city];
		memset(dp,inf,sizeof dp);
		for(int T=0;T<road;T++){
			int c1,c2,distant;
			cin >> c1 >> c2 >> distant;
			dp[c1][c2]=distant;
			dp[c2][c1]=distant;
		}
		int inter,city1,city2;
		for(inter=0;inter<city;inter++){
			for(city1=0;city1<city;city1++){
				for(city2=0;city2<city;city2++){
					if(dp[city1][city2]>dp[city1][inter]+dp[inter][city2])  dp[city1][city2]=dp[city1][inter]+dp[inter][city2];
				}
			}
		}
		int sum_length[city];
		memset(sum_length,0,sizeof sum_length);
		for(int c=0;c<city;c++){
			for(int csub=0;csub<city;csub++){
				if(c!=csub) sum_length[c]+=dp[c][csub];
			}
		}
		int _min=inf;
		int position=0;
		for(int c=0;c<city;c++){
			if(sum_length[c]<_min){
				position=c;
				_min=sum_length[c];
			}
		}
		cout << position << endl;
	}
}