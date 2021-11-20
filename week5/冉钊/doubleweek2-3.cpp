#include<bits/stdc++.h>
using namespace std;
int n,e,temp,number[20020]={0},ans[20020],numans=0;
//number用于记录每个节点的connect
//ans用于记录答案
//numans用于记录ans中的元素length
bool vst[20020]={0};
int brother[20020][20020]={0};//存每一个数字的线
void dfs(int start){
     if(vst[start]) return;
     else{
        vst[start]=1;
        ans[numans++]=start;
        int z=number[start];
        sort(brother[start],brother[start]+z);
        for(int i=0;i<number[start];i++){
            temp=brother[start][i];
            dfs(temp);
        }
     }
}//深度搜索
int main (){
    cin>>n>>e;
    int c,d;
    for(int i=0;i<e;i++){
        cin>>c>>d;
        brother[c][number[c]]=d;
        number[c]+=1;
    }
    for(int i=0;i<n;i++){
        if(!vst[i])
        dfs(i);
    }//遍历每一个起点
    for(int i=0;i<numans;i++)
    cout<<ans[i]<<" ";
    return 0;
}