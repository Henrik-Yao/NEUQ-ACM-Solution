#include<bits/stdc++.h>
using namespace std;
const int k = 1e4;
int pre[k];

int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}

int Find(int a){
    return pre[a] == a ? a : Find(pre[a]);
}

void add(int a,int b){
    a = Find(a);
    b = Find(b);
    if(a != b){
        pre[a] = b;
    }
}

int main(){
    int n,m,q;
    n = read(),m = read(),q = read();
    for(int i=1;i<=n;++i){
		pre[i]=i;
	}
    for(int i=1; i<=m; i++){
        int a,b;
        a = read(),b = read();
        add(a,b);
    }
    for(int i=0; i<q; i++){
        int a,b;
        a = read(), b = read();
        if(Find(a) == Find(b)){
            printf("In the same gang.\n");
        }
        else{
            printf("In different gangs.\n");
        }
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(pre[i] == i){
            cnt++;
        }
    }
    cout << cnt;
}
