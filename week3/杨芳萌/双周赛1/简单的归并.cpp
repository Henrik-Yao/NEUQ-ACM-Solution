#include<bits/stdc++.h>
using namespace std;
const int N = 233;
int n,m,T,a[N];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

bool cmp(int a,int b) {
	return a<b;
}

int main(){
	read(T);
	while(T--) {
		read(m);
		for(int i=1; i<=m; i++) read(a[i]);
		read(n);
		for(int i=m+1; i<=m+n; i++) read(a[i]);
		sort(a+1,a+n+m+1,cmp);
		for(int i=1; i<=m+n; i++) 	
			if(i!=n+m) printf("%d ",a[i]);
			else printf("%d",a[i]);
		printf("\n");
	}
    return 0;
}

