#include <bits/stdc++.h>
using namespace std;
int l,w;                //l����w��
int start_x, start_y, end_x, end_y; //��㣬�յ�
int map1[100][100]; //��¼ͼ
int dis[100][100];  //��¼��㵽����һ��ľ���(������ֵ)
int ans[100][2];      //�����մ𰸵���������
int path[100][2];     //�浽���е��ͨ��·��(��ʱ����)
int dirx[4]={0,0,-1,1};
int diry[4]={1,-1,0,0}; //λ�Ʊ���
int cnt=0;              //��¼����·��·�߾�������
int sum=0;              //��¼���մ𰸵ľ�������
void search(int x,int y)
{
    if(x==end_x&&y==end_y)
    {
        for(int i=0;i<cnt;i++)
        {
            ans[i][0]=path[i][0];
            ans[i][1]=path[i][1];//·�����óɹ�����·������������·����
        }
        sum=cnt;    //·������ֵ
        return;
    }
    for(int i=0;i<4;i++)
    {
        int dx=x+dirx[i];
        int dy=y+diry[i];
        if(map1[dx][dy]!=-1&&(dx<l&&dx>=0)&&(dy<=w&&dy>=0)&&dis[x][y]+map1[dx][dy]<dis[dx][dy])
        {
            //�����㣬˵���ǿ���ѡ����н��
            dis[dx][dy]=dis[x][y]+map1[dx][dy];
            path[cnt][0]=dx;
            path[cnt][1]=dy;
            cnt++;
            search(dx,dy);
            cnt--; //�ؼ��еĹؼ���һ��Ҫ���ݣ��������·���ܵ��յ㣬ֱ��һ��һ����ݣ��׳������á�
        }
    }
}
int main()
{
    memset(dis,0x3f,sizeof(dis));
    cin >> l >> w;
    cin >> start_x >> start_y >> end_x >> end_y;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cin >> map1[i][j];
        }
    }
    int s=start_x,e=start_y;
    dis[s][e]=map1[s][e];  //������ȸ���
    path[cnt][0]=s;
    path[cnt][1]=e;      //���������·����
    cnt++;
    search(s,e);
    for(int i=sum-1;i>=0;i--)
    cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<")";
    return 0;
}
/*
10 10
3 6 8 8
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1  2  1  1  1  1  1  5  1 -1
-1  1  9  9  9  1  1 -1  1 -1
-1  1  1  1  1  1  1 -1  1 -1
-1  1 -1 -1 -1 -1 -1 -1  1 -1
-1  1  9  9  9  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  2 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
/*
 --------------------------->x
|��0��ʼ
|
|
|
|
|
|
|
^y
*/
/*


*/