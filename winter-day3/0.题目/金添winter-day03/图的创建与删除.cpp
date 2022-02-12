#include <bits/stdc++.h>
using namespace std;
struct edge //����һ����
{
    int start;  //����λ���
    int next;   //��һ����λ
    int length; //Ȩֵ
};
bool cmp(edge a, edge b)
{
    if (a.start != b.start)
        return a.start < b.start;
    else
        return a.next < b.next;
}
edge Edge[20001];
int start_count[20000]; //��¼�Ӹýڵ㿪ʼ�ıߵĸ���
bool visit[20001];
int main()
{
    int n, e;
    int count = 0;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> Edge[i].start >> Edge[i].next >> Edge[i].length;
        start_count[Edge[i].start]++; //�Ӹýڵ�����ı߸���++
        count++;                      //�ߵ��ܸ���++
    }
    sort(Edge, Edge + count, cmp);
    int d; //Ҫɾ���ĸ���
    cin >> d;
    for (int i = 0; i < d; i++)
    {
        int d_start, d_next;
        cin >> d_start >> d_next;
        for (int i = 0; i < count; i++)
        {
            if (Edge[i].start == d_start && Edge[i].next == d_next)
            {
                Edge[i].next = Edge[i].start;
                start_count[Edge[i].start]--;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        // continue;
        if (!visit[Edge[i].start]&&Edge[i].start != Edge[i].next)
        {
            cout << Edge[i].start << ":";
            visit[Edge[i].start] = 1;
        }
        if (start_count[Edge[i].start])
        {
            if (Edge[i].start != Edge[i].next)
            {
                cout << "(" << Edge[i].start << "," << Edge[i].next << "," << Edge[i].length << ")";
                start_count[Edge[i].start]--;
            }
            if (start_count[Edge[i].start] == 0)
                cout << endl;
        }
    }
    return 0;
}