#include<bits/stdc++.h>
using namespace std;
const int N=114;
struct node{
    int x;
    int h;
}tree[4*N];
int n;
int visit[4*N];
int m;
int a[N];
int num;
void build(int now,int h){
       for(int i=now;i<=now*2-1;i++){
       	tree[i].x=a[++m];
       	tree[i].h=h;
       	if(i>n)return;
	   }
	   build(now*2,h+1);
 }

void zhong(int pos)
{
    if(tree[pos].x==0) return;
    zhong(pos*2);
    cout<<tree[pos].x;
     num--;
    if(num>=1)cout<<" ";
    zhong(pos*2+1);
	}
int main(){
    int T;
    cin>>T;
    while(T--){
    m=0;
    cin>>n;
    num=n;
    memset(visit,0,sizeof(visit));
    memset(tree,0,sizeof(tree));
    memset(a,0,sizeof(a));
    int index;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]!=0)index=i;
    else num--;
   }
    build(1,1);
    int num=0;
    zhong(1);
    cout<<endl;
    while(index>0){
    	index=index/2;
    	num++;
	}
   
    cout<<num<<endl;
}
    return 0;
}
