#include <bits/stdc++.h>
using namespace std;
// kruskal ��³˹�����㷨
//����С������
struct edge
{
    int cost;  //Ȩֵ
    int next;  //�յ�
    int start; //��ʼ
};
bool cmp(edge a, edge b)
{
    return a.cost < b.cost; //��Ȩֵ����
}
int bond[2000]; //���鼯����
int num = 0;
int bond_generate(int n) //�ж������㼯���Ƿ���ͨ
{
    if (bond[n] == n)
        return n;
    if (bond[n] != n)
        return bond_generate(bond[n]);
}
int main()
{
    int n, e; // nΪ1-n���ڵ㣬e����ߵĸ���
    while (cin >> n >> e) //��������
    {
        num=0;
        edge Edge[2000];
        for (int i = 0; i < e; i++)
        {
            int remp1,remp2,remp3;
            cin>>remp1>>remp2>>remp3;
            Edge[num].start=remp1;Edge[num].next=remp2;Edge[num].cost=remp3;
            num++;
        }
        for (int i = 1; i <= n; i++)
            bond[i] = i; //���и���ֵ
        
        // ��ʼ����MST
        sort(Edge,Edge+num,cmp);
        int mst=0;int num_mst=0;
        for(int i=0;i<num;i++)
        {
            if(bond_generate(Edge[i].start)!=bond_generate(Edge[i].next))
            {//ֻҪ����ͬһ���ϣ��ͺϲ������˱߼���mst
                mst+=Edge[i].cost;
                bond[bond_generate(Edge[i].start)]=bond[Edge[i].next];
                num_mst++;
            }
            if(num_mst==n-1)
                break;
        }
        int judge=bond_generate(1);
        bool flag=1;
        for(int i=1;i<=n;i++)//�жϵ����Ƿ��������mst
        {
            if(bond_generate(i)!=judge)
            flag=0;
        }//���mst�ɹ����ɣ���ô���е����е�ض�ͬ��һ�����ϣ������е����������һ���㲻����������ϣ���˵��mst����ʧ��
        if(flag)
        cout<<mst<<endl;
        else 
        cout<<"There is no minimum spanning tree."<<endl;
        memset(bond,0,sizeof(bond));
    }

    return 0;
}