#include <cstdio>
#include <algorithm>
#define N 100001
using namespace std;

int n,m,a[N];

int pd(int l){
	int sum = 0,ls = 1;
	for(int i = 2;i <= n;i ++)
		if(a[i] - a[ls] >= l){
			sum ++;
			ls = i;
		}
	return sum >= m - 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	sort(a , a + n + 1);
	int l = 1,r = a[n] - a[1];
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(pd(mid)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%d",r);
	return 0;
}
