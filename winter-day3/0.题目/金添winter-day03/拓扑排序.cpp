#include <bits/stdc++.h>
using namespace std;
//��������
//STL�����ĵ�һ��ʹ�ã�
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int>edge[110];//��¼���б߹�ϵ
        queue<int> q;
        vector<int> aov;//��������
        int in[110];    //�������
        memset(in,0,sizeof(in));
        for(int i=0;i<m;i++)
        {
            int d,u;
            cin>>d>>u;  //dӦ����u��
            in[u]++;    //�ں����u���Ӧ++
            edge[d].push_back(u); //��u����d��next������
        }
        //��ʼ������������
        for(int i=1;i<=n;i++)
        if(in[i]==0)
        q.push(i);      //�����Ϊ0��һ��Ԫ������

        while(!q.empty())
        {
            int p=q.front();
            q.pop();    //�����Ϊ0��Ԫ�س���
            aov.push_back(p); //�ó��ӵĽ�����������
            for(int i=0;i<edge[p].size();i++)
            {
                in[edge[p][i]]--;//p�����Ԫ�����--
                if(in[edge[p][i]]==0)
                q.push(edge[p][i]);
            }
        }
        for(int i=0;i<aov.size();i++)
        cout<<aov[i]<<" ";
        cout<<endl;
    }
    return 0;
}