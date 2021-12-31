#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
int n,t;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
bool prime(int n) {
	for(int i=2; i*i<=n; i++) if(n%i==0) return 0;
    return 1;
}
int main(){
	read(t);
	while(t--) {
		read(n);
		if(n%2==0) printf("2\n");
		else if(prime(n)) printf("1\n");
		else if(prime(n-2)) printf("2\n");
		else printf("3\n");
	}
    return 0;
}

