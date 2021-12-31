#include<iostream>
#include<cstring>
using namespace std;
int n,m,Map[21][21],view[21][21],flag=0,total,boom;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int Count(int x,int y)
{
    int num=0;
    for(int o=0;o<8;o++)
    {
        if( x+dx[o]<0 || y+dy[o]<0 || x+dx[o]==n || y+dy[o]==m) continue;
        if(Map[x+dx[o]][y+dy[o]]==1) num++;
    }
    return num;
}

void press(int x,int y)
{
    if(x<0 || y<0 || x==n || y==m) return ;
    if(Map[x][y]==1)
    {
        flag=-1;
        return ;
    }
    total--;

    view[x][y]=Count(x,y);
    if(view[x][y]==0) 
        for(int o=0;o<8;o++)
        {
            if(view[x+dx[o]][y+dy[o]]==-1) press(x+dx[o],y+dy[o]);
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
        Map[i][j]=1;
    }
    memset(view,-1,sizeof(view));
    for(int o=1;o<=l;o++)
    {
        cin>>i>>j;
        flag=0;
        if(view[i][j]!=-1) continue;
        press(i,j);
        if(flag==-1)
        {
            cout<<"You lose\n";
            break;
        }
        for(int p=0;p<n;p++)
        {
            for(int q=0;q<m;q++)
            {
                cout<<view[p][q]<<" ";
            }
            cout<<"\n";
        }
        if(flag==1)
        {
            cout<<"You win\n";
            return 0;
        }
        cout<<"\n";
    }
    return 0;
}