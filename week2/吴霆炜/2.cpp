#include <bits/stdc++.h>
using namespace std;
#define max_N 10005

struct city{
	int x;
	int y;
};
int ans[max_N];
int M,N;
int main(){
	city c[max_N] = {0};
	cin>>N>>M;
	int i;
	int k;
	for(i = 1;i <= M;i++){
		cin>>c[i].x>>c[i].y;
	}
	cin>>k;
	while(k--){
		memset(ans,0,sizeof(ans));
		int p;
		cin>>p;
		for(i = 1;i <= p;i++){
			int v;
			cin>>v;
			ans[v] = 1;
		}
		bool flag = 0;
		for(i = 1;i <= M;i++){
			if(ans[c[i].x] == 0 && ans[c[i].y] == 0){
			flag = 1;
			break;
			}
		}
		if(!flag)
		puts("YES");
		else
		puts("NO");
	}
	return 0;
}