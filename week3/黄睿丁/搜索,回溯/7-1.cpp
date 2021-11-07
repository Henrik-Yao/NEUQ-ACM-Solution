#include <iostream>
#include <queue>
using namespace std;
int a[51],b[101][101];
int main()
{
    int m,n,k,i,j,l;
    cin>>m>>n>>k;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<k;i++)
    {
        cin>>j>>l;
        b[j][l]=1;
        b[l][j]=1;
    }
    int s,d;
    cin>>s>>d;
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(d==a[i])
        {
            flag=1;
            break;
        }
    }
    queue<int>lie;
    if(flag==0)
        cout<<"The city "<<d<<" is not safe!";
    else
    {
        flag=0;
        int now;
        lie.push(s);
        while(!lie.empty())
        {
            now=lie.front();
            lie.pop();
            a[now]=1;
            for(i=0;i<m;i++)
                if(b[now][i]==1&&a[i]!=1)
                {
                    if(i==d)
                        flag=1;
                    lie.push(i);
                }
            if(flag==1)
                break;
        }
        if(flag==1)
            cout<<"The city "<<d<<" can arrive safely£¡";
        else
            cout<<"The city "<<d<<" can not arrive safely£¡";
    }
    
}
