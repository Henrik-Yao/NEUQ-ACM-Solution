#include <bits/stdc++.h>
#define INF 1e8;
using namespace std;
int a[65];
int main(){
	int n,i,j;
	a[1]=1;a[2]=3;
	for(i=3;i<=64;i++){
		int min=INF;
		for(j=1;j<i;j++){
			if(2*a[j]+pow(2,i-j)-1<min) min=2*a[j]+pow(2,i-j)-1;
		}
		a[i]=min;
	}
while(scanf("%d",&n)!=EOF){
	printf("%d\n",a[n]);
}


return 0;

}
