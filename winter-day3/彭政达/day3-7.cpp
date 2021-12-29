/*
7-7 特殊最小成本修路
n个城镇之间目前有一些道路连接，但道路都是年久失修的土道。
现在政府准备将其中一些土道改造为标准公路，希望标准公路能够将所有城镇连通且总成本最小，
但其中有一个城镇比较特殊，受地形等限制，最多只能有两条标准公路通过该镇。
请编写程序，找出一种满足上述条件的、总成本最小的改造方案，若不存在改造方案，则亦能识别。
假定道路是双向的。
输入格式:
输入包含多组数据。每组数据第一行是3个整数n、v和e，均不超过50，n为城镇数目，
城镇编号0至n-1。v为最能有两条标准公路的城镇编号，e为现有的土路条数，
接下来是e行表示每条道路信息，每行为3个非负整数a、b、c，表示城镇a和城镇b间现有一条道路，
若将其改造为标准公路，成本为c。
输出格式:
对每组数据输出一行，为一个整数，表示满足要求的最小成本，若不存在改造方案，则输出-1。
输入样例:
5 0 8
0 1 1
0 2 1
0 3 1
0 4 1
1 4 100
1 2 100
2 3 100
3 4 100
5 0 4
0 1 1
0 2 1
0 3 1
0 4 1
输出样例:
202
-1
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int from,to,weight;
}s[64];
int father[64];
bool cmp(node a,node b){
    if(a.weight<b.weight) return true;
    else return false;
}
int find(int x){
    int a=x ;
    while(x!=father[x]) x=father[x];
    while(a!=father[a]){
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}
int main(){
    int n,v,e;
    while(cin>>n>>v>>e){
        int i;
        for(i=0;i<e;i++) cin>>s[i].a>>s[i].b>>s[i].cost;
        sort(s,s+e,cmp);
        for(i=0;i<64;i++) father[i]=i;
        int count=0,num=0,sum=0;
        for(i=0;i<e;i++){
            if(s[i].from==v || s[i].to==v){
                int fa=find(s[i].a),fb=find(s[i].b);
                if(count<2 && fa!=fb){
                    count++;num++;
                    sum+=s[i].weight;
                    father[fa]=fb;
                }
            }
			else if(s[i].from!=v && s[i].to!=v){
                int fa=find(s[i].from);
                int fb=find(s[i].to);
                if(fa!=fb){
                    num++;
                    sum+=s[i].cost;
                    father[fa]=fb;
                }
            }
            if(num==n-1) break;
        }
        if(num==n-1) cout<<sum<<endl;
        else cout<<-1<<endl;
    }
}
