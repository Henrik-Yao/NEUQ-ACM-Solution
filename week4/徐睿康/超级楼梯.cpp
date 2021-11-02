#include<bits/stdc++.h>
using namespace std;
int n,a[110],b;
int main(){
	scanf("%d",&n);
	a[2]=1;
	a[3]=2;
	for(int i=4;i<=40;i++)a[i]=a[i-1]+a[i-2];
	while(n--){
		scanf("%d",&b);
		printf("%d\n",a[b]);
	}
	return 0;
}
