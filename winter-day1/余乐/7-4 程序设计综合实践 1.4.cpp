#include <cstdio>
using namespace std;
int a[10001],t,n,js,os;
int main(){
	int b;
	while(~scanf("%d",&b)) a[++t]=b;n=t;
	for(int i=1;i<n;i++)
		for(int j=1;j<=n-i;j++)
			if(a[j]>a[j+1]){
				int c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
	for(int i=1;i<=n;i++)
		if(a[i]%2==0) os++;
		else js++;
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
		if(i<n) printf("->");
	}
	printf("\n");
	for(int i=1;i<=n;i++)
		if(a[i]%2==1){
			printf("%d",a[i]);
			js--;
			if(js>=1) printf("->");
		}	
	printf("\n");
	for(int i=1;i<=n;i++)
		if(a[i]%2==0){
			printf("%d",a[i]);
			os--;
			if(os>=1) printf("->");
		}
	return 0;
}
