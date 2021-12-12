#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
int a[N], n, cnt=1, now=0;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

int to(int l,int r){
    int ans = l;
    for(int i=l; i<=r; i++)
        if(a[l] < a[i]+i-ans) ans = i;
    return ans;
}

int find(int l,int r){
    int ans = l+1;
    for(int i=l; i<=r; i++)
        if(a[i]>a[ans]){
            a[ans] = a[i];
            ans = i;
        }
    return ans;
}

int main(){
    read(n);
    for(int i=0; i<n; i++) read(a[i]);
    while(now+a[now] < n-1){
        int tmp = a[now];
        int m = find(now, now+a[now]);
        now =  to(m, now+tmp);
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}

