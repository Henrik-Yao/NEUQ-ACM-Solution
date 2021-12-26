#include<bits/stdc++.h>
using namespace std;
struct customer{
    string name;
    int begintime,lasttime,time;
}p[10001];
bool vis[10001];
int x,cnt,m,n,sum=0,ans=0,timer=0;
map<string,int>mp;
queue<customer>okline;
int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    memset(vis,false,sizeof(vis));
    string name;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        for(int j=0;j<x;j++){
            cin>>name;
            mp[name]=i;
        }
    }
    cnt=m+1;
    for(int i=0;i<n;i++){
        cin>>p[i].name>>p[i].begintime>>p[i].lasttime;
        if(mp[p[i].name]==0) mp[p[i].name]=cnt++;
        if(p[i].lasttime>60) p[i].lasttime=60;
    }
    for(int i=0;i<n;i++)
        if(!vis[i]){
            vis[i]=true;
            if(timer<p[i].begintime) timer=p[i].begintime;
            p[i].time=timer-p[i].begintime;
            timer+=p[i].lasttime;
            okline.push(p[i]);
            for(int j=i+1; j<n; j++)
                if(!vis[j])
                    if(mp[p[i].name]==mp[p[j].name])
                        if(p[j].begintime<=timer){
                            vis[j]=true;
                            p[j].time=timer-p[j].begintime;
                            timer+=p[j].lasttime;
                            okline.push(p[j]);
                        }
                        else break;
        }
    while(!okline.empty()){
        cout<<okline.front().name<<endl;
        ans+=okline.front().time;
        okline.pop();
    }
    cout<<setiosflags(ios::fixed) <<setprecision(1) <<ans/(double)n<<endl;
}
