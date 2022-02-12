#include <bits/stdc++.h>
using namespace std;
#define maxn 1000

int pre[maxn],stk[maxn];//stk存储的是每个数在树中的层数，pre存储的是当前数的父结点
stack<int>s;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
    int a,b,n = 1,t;//n用于模拟层数的变化，初始化为1层
    scanf("%d",&a);//如果不先输入一个a的话，无法进入循环
    stk[a] = n++;
    s.push(a);
    while(!s.empty()){
        scanf("%d",&a);
        if(a){
            stk[a] = n++;
            pre[a] = s.top();
            s.push(a);
        }
        else{
            s.pop();
            n--;
        }
    }
    scanf("%d",&a);
    scanf("%d %d",&a,&b);
    if(stk[a] > stk[b]){//将两边都调整到同一层
        t = stk[a] - stk[b];
        while(t--){
            a = pre[a];
        }
    }
    else{
        t = stk[b] - stk[a];
        while(t--){
            b = pre[b];
        } 
    }
    while(pre[a] != pre[b]){
        a = pre[a];
        b = pre[b];
    }
    printf("%d\n",pre[a]);
    while(!s.empty())s.pop();
    memset(pre,0,sizeof(pre));
    memset(stk,0,sizeof(stk));
    }
    return 0;
}