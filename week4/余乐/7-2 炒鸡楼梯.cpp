#include <cstdio>
using namespace std;
int n,y,a[41];
int main(){
	a[1]=1;
	for(int i=2;i<=40;i++) a[i]=a[i-1]+a[i-2];
    a[1]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&y);
		printf("%d\n",a[y]);
	}
	return 0;
}
