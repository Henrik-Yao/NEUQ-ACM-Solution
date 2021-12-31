#include<iostream>
#include<map>
#include<queue>
using namespace std;
map<string,int>circle;
map<string,bool>judge;
struct customer
{
    string name;
    int arrive;
    int time;
}people[10001];
int main()
{
    int n,m;
    double t=0,wait=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int nn;
        string name;
        cin>>nn;
        for(int j=1;j<=nn;j++)
        {
            cin>>name;
            circle[name]=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>people[i].name>>people[i].arrive>>people[i].time;
        people[i].time=min(60,people[i].time);
    }
    for(int i=1;i<=n;i++)
    {
        if(judge[people[i].name]==1) continue;
        judge[people[i].name]=1;
        if(people[i].arrive>t) t=people[i].arrive+people[i].time;
        else
        {
            wait=wait+t-people[i].arrive;
            t=t+people[i].time;
        }
        cout<<people[i].name<<"\n";
        for(int j=i+1;j<=n;j++)
        {
            if(people[j].arrive>t) break;
            if(circle[people[i].name]==circle[people[j].name] 
            && circle[people[i].name]!=0 && judge[people[j].name]!=1)
            {
                judge[people[j].name]=1;
                wait=wait+t-people[j].arrive;
                t=t+people[j].time;
                cout<<people[j].name<<"\n";
            }
        }
    }
    printf("%.1lf",wait/n);
    return 0;
}