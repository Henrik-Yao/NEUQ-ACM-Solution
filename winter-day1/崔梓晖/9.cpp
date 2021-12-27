#include<bits/stdc++.h>
using namespace std;
struct gk
{
    string name;
    int begin;
    int end;
    int time;
}a[10001];
map<string,int>mp;
queue<gk>okline;
bool vis[10001];
int main()
{
	int n,m,sum=0,ans=0,timer=0;
    memset(vis,false,sizeof(vis));
    cin>>n>>m;
    int x,cnt;
    string name;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        for(int j=0;j<x;j++)
        {
            cin>>name;
            mp[name]=i;
        }
    }
    cnt=m+1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].name>>a[i].begin>>a[i].end;
        if(mp[a[i].name]==0)
        {
            cnt++;
            mp[a[i].name]=cnt;
		}
        if(a[i].end>60)
        {
            a[i].end=60;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            if(timer<a[i].begin)
            {
                timer=a[i].begin;
            }
            a[i].time=timer-a[i].begin;
            timer+=a[i].end;
            okline.push(a[i]);
            for(int j=i+1;j<n;j++)
            {
                if(!vis[j])
                {
                    if(mp[a[i].name]==mp[a[j].name])
                    {
                        if(a[j].begin<=timer)
                        {
                            vis[j]=true;
                            a[j].time=timer-a[j].begin;
                            timer+=a[j].end;
                            okline.push(a[j]);
                        }
                        else
                            break;
                    }
                }
            }
        }
    }
    while(!okline.empty())
    {
        cout<<okline.front().name<<endl;
        ans+=okline.front().time;
        okline.pop();
    }
    printf("%.1f",1.0*ans/n);
    return 0;
}

