#include <cstdio>
#define N 1001
using namespace std;

int n,x,a[N];

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	scanf("%d",&x);
	int l = 1,r = n,ans = 0;
	while(l <= r){
		ans ++;
		int mid = l + (r - l) / 2;
		if(a[mid] > x) r = mid - 1;
		else l = mid + 1;
	}
	if(a[r] != x) printf("-1\n");
	else printf("%d\n",r - 1);
	printf("%d",ans);
	return 0;
}
