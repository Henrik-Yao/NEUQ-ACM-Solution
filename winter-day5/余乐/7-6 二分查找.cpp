#include <cstdio>
#include <algorithm>
#define N 1001
using namespace std;

int n,m,a[N];

int main(){
	while(~scanf("%d",&n)){
		for(int i = 1;i <= n;i ++)
			scanf("%d",&a[i]);
		sort(a , a + n + 1);
		for(int i = 1;i <= n;i ++){
			printf("%d",a[i]);
			if(i < n) printf(" ");
		}	
		printf("\n");
		scanf("%d",&m);
		while(m --){
			int x,l = 1,r = n;
			scanf("%d",&x);
			while(l <= r){
				int mid = l + (r - l) / 2;
				if(a[mid] > x) r = mid - 1;
				else l = mid + 1;
			}
			if(a[r] != x) printf("0");
			else printf("%d",r);
			if(m > 0) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
