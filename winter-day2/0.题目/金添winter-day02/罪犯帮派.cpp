#include <bits/stdc++.h>
using namespace std;
//���鼯
int member[1001];
int search(int n)
{
    if (member[n] == n)
        return n; //����Ϊ������
    else
        return search(member[n]); //��ѯ�ð��ɺ�Ĵ�����
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        member[i] = i; //����ֵ

    for (int i = 0; i < m; i++)
    {
        int remp1, remp2;
        cin >> remp1 >> remp2;
        if (remp1 > remp2)
            swap(remp1, remp2); //ȷ��remp2>remp1
        member[search(remp1)] = member[remp2]; //���������ɺϲ�������һ�����ɵ��ϴ�������һ�����ɵ��ϴ�
    }
    for (int i = 0; i < q; i++)
    {
        int remp1, remp2;
        cin >> remp1 >> remp2;
        if (search(remp1) == search(remp2))
        {
            cout << "In the same gang." << endl;
        }
        else
        {
            cout << "In different gangs." << endl;
        }
    }
    int sum = 0; //��������
    for (int i = 1; i <= n; i++)
    {
        if (member[i] == i)
            sum++;
    }
    cout << sum << endl;
    return 0;
}