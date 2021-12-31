#include <iostream>
using namespace std;
int a[20][20],b[20][20],flag=0;
int c[8][8]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{-1,-1},{1,-1}};
void dian(int x,int y);
int main()
{
    int n,m,l,i,j,k,z;
    cin>>n>>m>>k>>l;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            b[i][j]=-1;
    for(i=0;i<k;i++)
    {
        cin>>j>>z;
        a[j][z]=1;
    }
    int c;
    for(i=0;i<l;i++)
    {
        cin>>j>>z;
        dian(j,z);
        for(c=0;c<n;c++)
        {
        for(j=0;j<m;j++)
            cout<<b[c][j]<<" ";
        cout<<endl;
        }
        if(flag==1)
            break;
            
    }
    
    int sum=0,f=0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
        	if(b[i][j]==-1)
        	sum++;
		}
        	if(sum!=k)
        	f=1;
    if(flag==1)
        cout<<"You lose";
    else if(f==0)
    {
        cout<<"You win"<<endl;
        
    }
    else
        cout<<endl;
}

void dian(int x,int y)
{
    int i,j,k;
    if(b[x][y]!=-1)
    return;
    else if(a[x][y]==1)
    {
        flag=1;
        return;
    }
    else
    {
        int s=0;
        for(i=0;i<8;i++)
        {
            if(a[x+c[i][0]][y+c[i][1]]==1)
            {
                s++;
            }
        }
        if(s>0)
        {
            b[x][y]=s;
            return;
        }
        else
        {
            b[x][y]=0;
            for(i=0;i<8;i++)
                dian(x+c[i][0],y+c[i][1]);
        }
    }
}
