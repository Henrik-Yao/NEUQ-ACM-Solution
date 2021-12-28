#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int t1;
    int t2;
    int powe;
    node(){
        t1=t2=powe=-1;
    }
}nod;
nod node[20021];
int flag[20021][20021];
int e[20021]={0};//用于储存边的数目，方便后续输出；
int N,E,K,s1,s2;
bool cmp(nod c,nod d){
    if(c.t1!=d.t1) return c.t1<d.t1;
    else return c.t2<d.t2;
}
int main(){
    scanf("%d %d",&N,&E);
    for(int i=0;i<E;i++){
        scanf("%d %d %d",&node[i].t1,&node[i].t2,&node[i].powe);
        e[node[i].t1]++;
        flag[node[i].t1][node[i].t2]=i;
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d%d",&s1,&s2);
        e[node[flag[s1][s2]].t1]--;
        node[flag[s1][s2]].t1=20021;
    }
    sort(node,node+E,cmp);

    int i=0,sum;
    while(i<E-K){
        sum=e[node[i].t1];
        printf("%d:",node[i].t1);
        for(int j=i;j<i+sum;j++){
            printf("(%d,%d,%d)",node[j].t1,node[j].t2,node[j].powe);
        }
        printf("\n");
        i+=sum;
    }
    return 0;
}
