#include<bits/stdc++.h>
using namespace std;
int p[1000],n,m;
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
struct node{
    int t,w,y;
    bool operator<(const node&t)const{
        return y<t.y;
    }
};
struct node a[10001];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    p[i]=i;
    for(int i=0;i<m;i++)
    cin>>a[i].t>>a[i].w>>a[i].y;
    sort(a,a+m);
    int res=0;
    for(int i=0;i<m;i++){
        int q1=find(a[i].t),q2=find(a[i].w),q3=a[i].y;
        if(q1!=q2){
            p[q1]=q2;
            res=q3;
        }
    }
    cout<<n-1<<" "<<res<<endl;
    return 0;
}
