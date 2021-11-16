#include <bits/stdc++.h>
#define max 50001
using namespace std;
int m[max];
bool vis[max];
int len,start;
bool tao(int start){
    if(m[start]==0) return true;
    if(vis[start]) return false;
    vis[start]=1;
    int pre,back;
    pre=start+m[start];
    back=start-m[start];
    if(pre>len-1&&back<0) return false;
    else if(pre>len-1){
        if(m[back]!=0) 
        {
            if(tao(back)) return true;
            else return false;
        }
        else return true;
    }
    else if(back<0){
        if(m[pre]!=0) 
        {
            if(tao(pre)) return true;
            else return false;
        }
        else return true;
    }
    else {
        if(!tao(pre)&&!tao(back)) return false;
        else return true;
    }
}
int main(){
    cin>>len;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<len;i++){
        cin>>m[i];
        vis[i]=0;
    }
    cin>>start;
    if(tao(start))
        cout<<"True";
    else cout<<"False";
}
