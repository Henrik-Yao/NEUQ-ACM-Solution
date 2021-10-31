#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s_x,s_y;
int num;
int ans[100004];
int inc[1002][1002];
char map[1002][1002];

void dfs(int x,int y,int mark,int has)
{
    if(x<0||x>=s_x)	return;
    if(y<0||y>=s_x)	return;
    if(inc[x][y]!=-1)	return;
    if(map[x][y]-'0'!=mark)	return;
    
    inc[x][y]=has;
	ans[has]++;
    
	dfs(x-1,y,!mark,has);
	dfs(x+1,y,!mark,has);
	dfs(x,y-1,!mark,has);
	dfs(x,y+1,!mark,has);
	return;
}

int main()
{
    cin>>s_x>>num;
    s_y=s_x;
    for (int i=0;i<s_x;i++)
    scanf("%s",map[i]);
    
    memset(inc,-1,sizeof(inc));
    
    for (int i=0;i<num;i++)
    {
    	int x,y;
        scanf("%d%d",&x,&y);
		x--;
		y--;
		
        if (inc[x][y]==-1)	dfs(x,y,map[x][y]-'0',i);
		else ans[i]=ans[inc[x][y]];
		
		printf("%d", ans[i]);
		if(i!=num-1)	printf("\n");
    }
    return 0;
}
