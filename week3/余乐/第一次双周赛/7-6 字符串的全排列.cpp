#include <cstdio>
#include <cstring>
using namespace std;
char a[11];
int pd[11],n,q[11];
void s(int p,int t){
	pd[p]=1;
	q[t]=p;
	if(t==n){
		pd[p]=0;
		for(int i=1;i<=n;i++) printf("%c",a[q[i]]);
		printf("\n");
		return;
	}
	for(int i=0;i<n;i++)
		if(pd[i]==0) s(i,t+1);
	pd[p]=0;
}
int main(){
	scanf("%s",a);
	n=strlen(a);
	for(int i=1;i<n;i++)
		for(int j=0;j<n-1;j++)
			if(a[j]>a[j+1]){
				char c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
	for(int i=0;i<n;i++) s(i,1);
	return 0;
}
