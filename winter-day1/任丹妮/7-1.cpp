#include <bits/stdc++.h>
using namespace std;
#define lowbit(i) ((i)&(-i))
long long a[1000010];
    int n,q;
void add(int x,int v){
    for(int i=x;i<=n;i=i+lowbit(i))
                a[i]+=v;
}
long long Sum(int l){
    long long sum=0;
    for(int i=l;i>0;i=i-lowbit(i)){
        sum=sum+a[i];
    }
    return sum;
}
int main(){
    cin>>n>>q;
     memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        add(i,m);
    }
    while(q--){
        int d,x,y;
        cin>>d>>x>>y;
        if(d==1) {
            add(x,y);
        }
        else {
            cout<<Sum(y)-Sum(x-1)<<endl;
        }
    }
    return 0;
}
