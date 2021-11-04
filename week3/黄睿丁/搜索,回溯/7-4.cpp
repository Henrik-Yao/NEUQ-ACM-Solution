#include <iostream>
using namespace std;
int n,a[1005][1005],b[1005][1005],c[1001*1001],dercition[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int zou(int x,int y,int tag);
int du()
{
	int y=0;
	char c;
	while(1)
	{
		c=getchar();
		if(c>='0'&&c<='9')
		break;
	}
	y=c-'0';
	return y;
}
int main()
{
    int m,i,j,x,y;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            a[i][j]=du();
            b[i][j]=-1;
        }
    int tag=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(b[i][j]==-1)
            {
                c[tag]=zou(i,j,tag);
                tag++;
            }
        }
        
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        cout<<c[b[x][y]]<<endl;
    }
    
}

int zou(int x,int y,int tag)
{
    int sum=1,i,j;
    b[x][y]=tag;
    for(i=0;i<4;i++)
    {
        if(a[x+dercition[i][0]][y+dercition[i][1]]+a[x][y]==1&&x+dercition[i][0]<=n&&y+dercition[i][1]<=n&&b[x+dercition[i][0]][y+dercition[i][1]]==-1)
        {
            sum+=zou(x+dercition[i][0],y+dercition[i][1],tag);
        }
    }
    return sum;
}
