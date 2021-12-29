#include <cstdio>
using namespace std;
int n,ans[66];
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		int a;
		scanf("%d",&a);
		ans[a] ++;
	}
	for(int i = 0;i <= 50;i ++)
		if(ans[i])
			printf("%d:%d\n",i,ans[i]);
	return 0;
} 
