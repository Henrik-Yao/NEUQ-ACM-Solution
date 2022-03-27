#include <bits/stdc++.h>
using namespace std;


int n,m,space1[21][21],space2[21][21],flag=0,total,boom,dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1};

void dean(int x,int y,int o)
{
    if(space2[x][y]==0) 
        for(int o=0;o<8;o++)
        {
            if(space2[x+dx[o]][y+dy[o]]==-1)
            return ;
        }
        for(int o=1;o<=y;o++)
    {
        cin>>x>>y;
        space1[x][y]=1;
    }
}

int f(int x,int y)
{
    int num=0;
    for(int o=0;o<8;o++)
    {
        if( x+dx[o]<0 || y+dy[o]<0 || x+dx[o]==n || y+dy[o]==m) continue;
        if(space1[x+dx[o]][y+dy[o]]==1) num++;
    }
    return num;
}

void press(int x,int y)
{
    if(x<0 || y<0 || x==n || y==m) return ;
    if(space1[x][y]==1)
    {
        flag=-1;
        return ;
    }
    total--;

    space2[x][y]=f(x,y);
    if(space2[x][y]==0) 
        for(int o=0;o<8;o++)
        {
            if(space2[x+dx[o]][y+dy[o]]==-1) press(x+dx[o],y+dy[o]);
        }

    if(total-boom==0)
    {
        flag=1;
        return ;
    }
    return ;
}

int main()
{
    int k,l,i,j;
    cin>>n>>m>>k>>l;
    total=n*m;
    boom=k;
    for(int o=1;o<=k;o++)
    {
        cin>>i>>j;
        space1[i][j]=1;
    }
    memset(space2,-1,sizeof(space2));
    for(int o=1;o<=l;o++)
    {
        cin>>i>>j;
        flag=0;
        if(space2[i][j]!=-1) continue;
        press(i,j);
        if(flag==-1)
        {
            cout<<"You lose"<<endl;
            break;
        }
        for(int p=0;p<n;p++)
        {
            for(int q=0;q<m;q++)
            {
                cout<<space2[p][q]<<" ";
            }
            cout<<endl;
        }
        if(flag==1)
        {
            cout<<"You win"<<endl;
            return 0;
        }
        cout<<endl;
    }
    return 0;
}
