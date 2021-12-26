#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 10000005
#define lowbit(i) ((i)&(-i))//获取最低位1
ll a[maxn];//树状数组
int n,q;

void update(int x,int y){
    for(int i = x;i <= n;i += lowbit(i)){
        a[i] += y;
    }
    return;
}

ll getsum(int x){
    ll sum = 0;
    for(int i = x;i;i -= lowbit(i)){
        sum += a[i];
    }
    return sum;
}

int main(){
    scanf("%d%d",&n,&q);
    memset(a,0,sizeof(a));
    for(int i = 1;i <= n;i++){
        int num;
        scanf("%d",&num);
        update(i,num);
    }
    while(q--){
        int opt,num_1,num_2;
        scanf("%d%d%d",&opt,&num_1,&num_2);
        if(opt == 1)
            update(num_1,num_2);  
        else{
            ll ans = getsum(num_2) - getsum(num_1 - 1);
            printf("%lld\n",ans); 
        }
    }
    return 0;
}