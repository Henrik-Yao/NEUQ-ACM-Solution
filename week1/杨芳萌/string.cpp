#include<bits/stdc++.h>
using namespace std;
int n;
char a[55555];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
int main(){
	read(n);
	scanf("%s",a+1);
	int len = strlen(a+1);
	for(int i=1; i<=n; i++) {
		string b;
		cin>>b;
		int cnt = 0;
		for(int j=1; j<=len; j++){
			int l = b.length();
			string tmp;
			for(int k=j; k<=j+l-1; k++) tmp += a[k];
			if(tmp==b) cnt++;
		}
		printf("%d\n",cnt);
	}
    return 0;
}

