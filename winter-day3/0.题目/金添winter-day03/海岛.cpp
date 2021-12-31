#include <bits/stdc++.h>
using namespace std;
int m, n;   //m��n��
int sum=0;  //��������
bool sea_map[110][110];      //��¼�����ͼ
bool visit[110][110];        //��¼�õؿ��Ƿ�����
int dirx[4] = {0, 0, -1, 1}; //λ�ƿ��� �� �� �� ��
int diry[4] = {1, -1, 0, 0};
void search(int x, int y)
{
    if (!(x <= m && x >= 1 && y >= 1 && y <= n))
        return;
    visit[x][y]=1;//�������
    for(int i=0;i<4;i++)
    {
        if(sea_map[x+dirx[i]][y+diry[i]]&&!visit[x+dirx[i]][y+diry[i]])
        search(x+dirx[i],y+diry[i]);
    }
    return;
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> sea_map[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!visit[i][j]&&sea_map[i][j])
            {
                search(i, j);  //�������������
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}