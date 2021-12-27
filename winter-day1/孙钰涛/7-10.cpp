#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int>line[100];
    int n,p,cnt=0,temp,flag;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        flag=0;
        for(int i=1;i<=cnt;i++)
        {
            if(temp<line[i].back())
            {
                line[i].push(temp);
                if(temp==1) p=i;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cnt++;
            line[cnt].push(temp);
            if(temp==1) p=cnt;
        }
    }
    while(!line[p].empty())
    {
        cout<<line[p].front();
        if(line[p].size()!=1) cout<<" ";
        line[p].pop();
    }
    cout<<"\n"<<cnt;
    return 0;
}