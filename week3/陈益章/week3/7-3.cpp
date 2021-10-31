#include<iostream>
#include<cstring>
using namespace std;
int n,m,wmpt[21][21],ace[21][21],flag=0,total,boom,dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1};
void dean(int x,int y,int o)
{
    if(ace[x][y]==0) 
        for(int o=0;o<8;o++)
        {
            if(ace[x+dx[o]][y+dy[o]]==-1)
            return ;
        }
        for(int o=1;o<=y;o++)
    {
        cin>>x>>y;
        wmpt[x][y]=1;
    }
}
int f(int x,int y)
{
    int num=0;
    for(int o=0;o<8;o++)
    {
        if( x+dx[o]<0 || y+dy[o]<0 || x+dx[o]==n || y+dy[o]==m) continue;
        if(wmpt[x+dx[o]][y+dy[o]]==1) num++;
    }
    return num;
}

void press(int x,int y)
{
    if(x<0 || y<0 || x==n || y==m) return ;
    if(wmpt[x][y]==1)
    {
        flag=-1;
        return ;
    }
    total--;

    ace[x][y]=f(x,y);
    if(ace[x][y]==0) 
        for(int o=0;o<8;o++)
        {
            if(ace[x+dx[o]][y+dy[o]]==-1) press(x+dx[o],y+dy[o]);
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
        wmpt[i][j]=1;
    }
    memset(ace,-1,sizeof(ace));
    for(int o=1;o<=l;o++)
    {
        cin>>i>>j;
        flag=0;
        if(ace[i][j]!=-1) continue;
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
                cout<<ace[p][q]<<" ";
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
