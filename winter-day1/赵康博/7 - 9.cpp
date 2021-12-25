#include<bits/stdc++.h>
using namespace std;
#define N 10000
struct custor{
    string name;
    int arrive;
    int time;
}c[N];
map<string,int> FriendH ,XvGet;
vector<string> circle[N],xun;
int v[N];
bool cmp(string a,string b)
{
    return XvGet[a] < XvGet[b];
}
int main() {
    int m,n;
    cin>>m>>n;
    for(int i = 0; i < n; i++)
    {
        int n1;
        string name;
        cin>>n1;
        for(int j = 0; j < n1; j++)
        {
            cin>>name;
            FriendH[name] = i;
            circle[i].push_back(name);
        }
    }
    for(int i = 0; i < m; i++)
    {
        cin>>c[i].name>>c[i].arrive>>c[i].time;
        if(c[i].time>60)c[i].time = 60;
        XvGet[c[i].name] = i;
    }
    memset(v,0, sizeof(int)*m);
    int sum = 0;
    int windowTime = c[0].arrive;
    for(int i = 0; i < m; i++)
    {
        if(v[i])continue;
        if(FriendH.find(c[i].name)==FriendH.end())
        {
            if(windowTime>c[i].arrive)
            {
                sum+=windowTime - c[i].arrive;
                windowTime+=c[i].time;
            }
            else
            {
                windowTime = c[i].arrive + c[i].time;
            }
            v[i] = 1;
            xun.push_back(c[i].name);
        }
        else
        {
            int ID = FriendH[c[i].name];
            sort(circle[ID].begin(),circle[ID].end(),cmp);
            for(int j = 0; j < circle[ID].size(); j++)
            {
                int x = XvGet[circle[ID][j]];
                if(c[x].arrive>windowTime&&j!=0)break;
                if(v[x])continue;
                if(c[x].arrive<=windowTime)
                {
                    sum+=windowTime - c[x].arrive;
                    windowTime+=c[x].time;
                }
                else windowTime = c[x].arrive+c[x].time;
                v[x] = 1;
                xun.push_back(c[x].name);
            }
        }
    }
    for(int i = 0; i < xun.size(); i++)cout<<xun[i].c_str()<<endl;
    printf("%.1f\n",sum*1.0/m);
    return 0;
}
