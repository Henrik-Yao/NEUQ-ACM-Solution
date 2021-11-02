#include<bits/stdc++.h>
using namespace std;
const int N = 233;
int n,m,f[N];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

int main(){
	read(n);
	while(n--) {
		read(m);
		if(m==1) { printf("0\n"); continue; }//??????? 
		f[1] = 1;
		for(int i=2; i<=m; i++) f[i] = f[i-1] + f[i-2];
		printf("%d\n",f[m]);
	}

    return 0;
}

