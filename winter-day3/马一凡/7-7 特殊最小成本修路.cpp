#include<algorithm>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<math.h>
#include<string>

using namespace std;

struct edge{
    int from,to;
    int vec;
};

edge a[90005]={0};

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
    int i,j,n,m,q,maxx,ans;
    int d1,d2;
    while(cin >> n >> q >> m){
	
        for(i=0;i<n;i++){
            pre[i]=i;
        }
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].vec);
        }
        
        sort(a,a+m,cmp);//为了贪心排序
        ans=0;
        maxx=0;
        int sum=0;
        int book=0;
        
        for(i=0;i<m;i++){
            d1=find(a[i].from);
            d2=find(a[i].to);
            
            if(d1!=d2)//不是一个集合就合并
            {
            	if(a[i].from == q || a[i].to == q){
            		if(book >= 2) continue;
            		else{
            			pre[d1]=d2;
                		ans++;
                		if(ans>n-1)
                  		  break;
                		sum = sum+a[i].vec;
                		book++;
					}
				}
            	else{
            		pre[d1]=d2;
                	ans++;
                	if(ans>n-1)
                 	   break;
                	sum = sum+a[i].vec;
				}
                
            }
        }
        int view=0;
        for(int i=0; i<n; i++){
        	if(pre[i] == i) view++;
		}
		if(view == 1)
        	printf("%d\n",sum);
        else cout << "-1" << endl;
	}
    return 0;
}
