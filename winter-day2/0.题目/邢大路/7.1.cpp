#include<bits/stdc++.h>
using namespace std;
const int N=114;
struct node{
    int h;
    int x;
}tree[4*N];
int visit[4*N];
int sum[N];
int n,m;
int a[N];
void build(int now,int h){
    if(!visit[now]){
        visit[now]=1;
        tree[now].x=a[++m];
        tree[now].h=h;
        if(a[m]==0)return;
    }
    build(now*2,h+1);
    build(now*2+1,h+1);
}
void Sum(int now){
    while(tree[now].x!=0){
    	if(tree[now*2].x==0&&tree[now*2+1].x==0)
        sum[tree[now].h]+=tree[now].x;
        Sum(now*2);
        Sum(now*2+1);
        break;
    }
}
int main(){
    m=0;
    n=0;
    int x;
    memset(visit,0,sizeof(visit));
    memset(sum,0,sizeof(sum));
    while(~scanf("%d",&x)){
        a[++n]=x;
    }
    build(1,0);
    Sum(1);
    int maxx=-100;
    int h=0;
    for(int i=0;i<10;i++){
        if(sum[i]>=maxx&&sum[i]!=0){
            maxx=sum[i];
            h=i;
        }
    }
    cout<<h<<endl;
    return 0;
}
