
#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int n,m;
bool lei[25][25];
// bool open[25][25];
int display[25][25];
int stepx[4] = {-1,0,1};
int stepy[4] = {-1,0,1};
void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d ",display[i][j]);
        printf("\n");
    }
}
void update(int x, int y)
{
    int cnt = 0;
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        {
            int nowx = x+stepx[i], nowy = y+stepy[j];
            if(nowx>=0&&nowx<n&&nowy>=0&&nowy<m&&!(nowx==x&&nowy==y))
                if(lei[nowx][nowy])
                    cnt++;
        }
    }
    display[x][y] = cnt;
    if(cnt==0)
    {
        for(int i=0;i<=2;i++)
        {
            for(int j=0;j<=2;j++)
            {
                int nowx = x+stepx[i], nowy = y+stepy[j];
                if(nowx>=0&&nowx<n&&nowy>=0&&nowy<m&&!(nowx==x&&nowy==y))
                    if(display[x+stepx[i]][y+stepy[j]]==-1)
                        update(x+stepx[i],y+stepy[j]);
            }
        }
    }
}
bool findifend()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(display[i][j]==-1&&lei[i][j]==false)
                return false;
    }
    return true;
}
int main()
{
//     freopen("readin.in","r",stdin);
    n = read(), m = read();
    int k = read(), l = read();
    memset(display,-1,sizeof(display));
    for(int i=1;i<=k;i++)
    {
        int x = read(), y = read();
        lei[x][y] = true;
    }
    for(int i=1;i<=l;i++)
    {
        int x = read(), y = read();
        if(display[x][y]!=-1){continue;}
        else if(lei[x][y]){cout<<"You lose";break;}
        update(x,y);
        print();
        if(findifend()){printf("You win");return 0;}
        printf("\n");
    }


}