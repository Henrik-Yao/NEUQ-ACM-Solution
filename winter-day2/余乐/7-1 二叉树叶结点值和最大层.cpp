#include <cstdio>
using namespace std;
int n,maxn = -999999999,Ans,t = 1,li;
int ans[101],q[101],v[101];
int build(int ce){
	int now = t;
	if(t > n) return 0;
	if(q[t ++] == 0) return 1;
	if(li < ce) li = ce;
	int sum = 0;
	sum += build(ce + 1);
	sum += build(ce + 1);
	if(sum == 2){
		ans[ce] += q[now];
		v[ce] = 1;
	}
}
int main(){
	int a;
	while(~scanf("%d",&a)) q[++n] = a;
	build(0);
	for(int i = li;i >= 0;i --)
		if(ans[i] > maxn && v[i] == 1){
			maxn = ans[i];
			Ans = i;
		}
	printf("%d\n",Ans);
	return 0;
}
