/*
7-4 ��������
����һ���� 1��½�أ��� 0��ˮ����ɵ�n*m�Ķ�ά����������������е��������num��
�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�������ֱ���������ڵ�½�������γɡ�����
��	��	��
0	0	0
0	1	0
0	0	1
��Ϊ��������
���⣬����Լ��������������߾���ˮ��Χ��1<=n,m<=100
�����ʽ:
��һ���и������񳤿�n,m ��������n�б�ʾ�������
�����ʽ:
�������num
��������:
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
�������:
3
*/
#include <bits/stdc++.h>
using namespace std;
int a[128][128];
int n,m,count;
int find(int x,int y){
    if(x>n || y>m || x<1 || y<1|| !a[x][y]) return 0;
    a[x][y]=0;
    find(x+1,y);
    find(x,y+1);
    find(x-1,y);
    find(x,y-1);
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(find(i,j)>0) count++;
    cout<<count;
}
