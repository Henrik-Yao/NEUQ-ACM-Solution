#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e6+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
bool ju = 1;
struct node{
    node(){l = r = NULL;}
    node *l, *r;
    char val;
};
int find(char *a, char c,int n){
    for(int i=0;i<n;++i) if(c == a[i])return i;
    return -1;
}
node* hahaha(int n, char *a, char *b) {
    if(n<=0 || ju==0) return NULL;
    node *x;
    x=new node;
    x->val=b[n-1];
    int t = find(a, b[n-1],n);
    if(t == -1) {ju = 0;return NULL;}
    x->l=hahaha(t,a,b);
    x->r=hahaha(n-t-1,a+t+1,b+t);
    return x;                  
} 
int ans = 0;
void Q(node *rt,int t){
    if(rt == NULL) return;
    cout << rt->val;
    Q(rt->l,t+1),Q(rt->r,t+1);
}
void A(node *rt,int t){
    if(rt == NULL) return;
    if(t > ans) ans = t;
    A(rt->l, t+1);
    A(rt->r, t+1);
}
char a[110], b[110];
int main() {
    while(~scanf("%s%s",b,a)){
        ju=1;
        node *rt=hahaha(strlen(b),a,b);
        if(ju){
            A(rt, 0);
            cout<<ans<<"\n";
            Q(rt,1);cout<<endl;
        }
        else cout<<"INVALID"<<endl;
    }
    return 0;
}
