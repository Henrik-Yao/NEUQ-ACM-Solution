#include <cstdio>
#include <algorithm>
#define N 1001
using namespace std;

int n,ans,a[N];

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	sort(a , a + n + 1);
	for(int i = 2;i <= n;i ++)
		if(a[i] == a[i - 1] + 1)
			ans ++;
	printf("%d\n",ans);
	return 0;
}
