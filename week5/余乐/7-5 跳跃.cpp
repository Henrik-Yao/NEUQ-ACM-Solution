#include <cstdio>
#define N 50001
using namespace std;
int a[N],u[N],n,st;
int y(int p){
	if(p<0||p>=n) return 0;
	if(u[p]) return 0;
	if(a[p]==0) return 1;
	u[p]=1;
	return y(p+a[p])+y(p-a[p]);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&st);
	if(y(st)) printf("True");
	else printf("False");
 	return 0;
}
