#include <bits/stdc++.h>
#define mm 100
using namespace std;
typedef struct 
{
    int city[mm][mm];
    int m,k;
}ditu;
int main()
{
    ditu map;
    int n;
    cin>>map.m>>n>>map.k;
    int i;
    int safe[mm];
    for(i=0;i<n;i++)cin>>safe[i];
    for(i=0;i<map.m;i++)
    {
        for(int j=0;j<map.m;j++)
        map.city[i][j]=0;
    }
    for(i=0;i<map.k;i++)
    {
        int x,y;
        cin>>x>>y;
        map.city[x][y]=1;
        map.city[y][x]=1;
    }
    int s,d;
    int f=0;
    cin>>s>>d;
    for(i=0;i<n;i++)
    {
        if(d==safe[i])
        {
            f=1;
            break;
        }
    }
    if(map.city[s][d]==1)
    {
        if(f)
        printf("The city %d can arrive safely!",d);
        else 
		printf("The city %d is not safe!",d);
    }
    else 
    {
        if(f)
		printf("The city %d can not arrive safely!",d);
		else 
        printf("The city %d is not safe!",d);
    }
    return 0;

}