#include<bits/stdc++.h>
using namespace std;
const int MIN = -0x7fffffff;
const int N = 2333;
int n,a[N],cnt;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

int main(){
	read(n);
	for(int i=1; i<=n; i++) read(a[i]);
	for(int i=1; i<=n; i++) 
		for(int j=i+1; j<=n; j++) 
			if(abs(a[i]-a[j])==1) cnt++; 
	printf("%d\n",cnt);
    return 0;
}

