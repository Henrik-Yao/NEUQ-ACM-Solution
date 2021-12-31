#include <map>
#include <cstdio>
#include <string>
#define N 16
using namespace std;

int n,ans,top,stack[N],a[N],f[N][N];

map<string,int> tr;

int pd(){
	char b[N]={'\0'};
	for(int i = 0;i < top;i ++)
		b[i] = stack[i + 1];
	if(tr[b]) return 0;
	tr[b] = 1;
//	for(int i = 1;i <= top;i ++)
//		printf("%d ",stack[i]);
//	printf("\n");
	return 1;
}
void solve(int p , int tot){
	stack[++ top] = a[p];
	if(tot >= 2)
		ans += pd();
	for(int i = p + 1;i <= n;i ++)
		if(a[i] >= a[p])
			solve(i , tot + 1);
	-- top;
} 
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	for(int i = 1;i < n;i ++)
		solve(i , 1); 
	printf("%d",ans);
	return 0;
}
