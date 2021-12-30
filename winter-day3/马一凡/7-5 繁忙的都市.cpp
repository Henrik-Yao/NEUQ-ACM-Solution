#include<algorithm>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<math.h>
#include<string>
#include<stdio.h>
#include<queue>
#include<stack>
#include<map>
#include<deque>
using namespace std;

struct edge{
    int from,to;
    int vec;
};

edge a[90005];

int cmp(edge x,edge y){
    return x.vec<y.vec;
}

int pre[305];

int find(int x)//并查集操作
{
    if(x!=pre[x])
        pre[x]=find(pre[x]);
    return pre[x];
}

int main(){
    int i,j,n,m,maxx,ans;
    int d1,d2;
    scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            pre[i]=i;
        }
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].vec);
        }
        
        sort(a,a+m,cmp);//为了贪心排序
        ans=0;
        maxx=0;
        
        for(i=0;i<m;i++){
            d1=find(a[i].from);
            d2=find(a[i].to);
            
            if(d1!=d2)//不是一个集合就合并
            {
                pre[d1]=d2;
                ans++;
                if(ans>n-1)
                    break;
                if(maxx<a[i].vec)
                    maxx=a[i].vec;
            }
        }
        printf("%d %d\n",n-1,maxx);
    
    return 0;
}
