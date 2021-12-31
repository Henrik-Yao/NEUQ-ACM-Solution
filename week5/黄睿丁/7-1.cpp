#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct human{
    char gender;
    int id_dad;
    int id_mom;
};
human people[100000];
int flag=0;
bool state[100000];
void dfs(int x,int f)
{
    if(f>5)
        return;
    if(x<=0)
        return;
    if(state[x]==1)
    {
        flag=1;
    }
    state[x]=1;
    dfs(people[x].id_dad,f+1);
    dfs(people[x].id_mom,f+1);
}
     
int main()
{
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        int id;
        cin>>id;
        cin>>people[id].gender>>people[id].id_dad>>people[id].id_mom;
        people[people[id].id_dad].gender='M';
        people[people[id].id_mom].gender='F';
    }
    
    int k;
    cin>>k;
    for(i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        if(people[a].gender==people[b].gender)
        cout<<"Never Mind"<<endl;
        else
        {
            memset(state,0,sizeof(state));
            flag=0;
            dfs(a,1);
            dfs(b,1);
            if(flag)
                cout<<"No";
            else
                cout<<"Yes";
            if(i!=k-1)
                cout<<endl;
        }
    }
}
