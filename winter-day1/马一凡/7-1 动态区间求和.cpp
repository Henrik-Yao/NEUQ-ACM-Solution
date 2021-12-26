#include<iostream>
#include<cstring>
#include<malloc.h>
#define lowbit(x) ((x) & -(x))
using namespace std;

long long sum(long long x, long long* c, long long n)
{
    long long ret = 0;
    for( ; x > 0; ret+=c[x], x-=lowbit(x));
    return ret;
}

void update(long long x, long long val, long long* c, long long n)
{
    for( ; x <= n; c[x]+=val, x+=lowbit(x));
}

int main()
{
    long long n,i,q;
    long long *arr=NULL, *c=NULL;

    cin >> n >> q;
    arr = (long long*)malloc((n + 1)*sizeof(long long));
    c = (long long*)malloc((n + 1)*sizeof(long long));
    memset(c,0,(n + 1)*sizeof(long long));
    for (i=1; i <= n; scanf("%lld", arr+i), update(i,arr[i],c,n), ++i);

    for (long long t=q; t>0; t--){
        long long num,x,y;
        cin >> num >> x >> y;
        if(num == 2)
            printf("%lld\n",sum(y,c,n)-sum(x-1,c,n));
        else if(num == 1){
            update(x,y,c,n);
            arr[x] += y;
        }
    }
    
    
    return 0;
}

