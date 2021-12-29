#include <cstdio>
#include <algorithm>
#define N 100001
using namespace std;

int n,m,a[N * 2];

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	for(int i = 1 + n;i <= n * 2;i ++)
		scanf("%d",&a[i]);
	sort(a , a + 2 * n + 1);
//	for(int i = 1;i <= n << 1;i ++)
//		printf("%d ",a[i]);
	printf("%d",a[(n * 2 + 1) / 2]);
	return 0;
}
