#include<bits/stdc++.h>
using namespace std;
struct act//��İ���
{
    int sta; int end;
}a[105];
bool cmp(act a,act b)
{
    return a.end < b.end; //������ʱ���С��������
}
int main()
{
    int t,n,maxa;
    cin >> t;
    while (t--)
    {
        maxa = 0;
        cin >> n;
        for (int i = 0; i < n;i++)//����
        {
            cin >> a[i].sta >> a[i].end;//��sta�㵽end��
        }
        sort(a, a + n, cmp);//����
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].sta < x) continue;//ȥ����ͻ��
            maxa++;
            x = a[i].end;
        }
        cout <<n-maxa<<endl;
        /*for (int i = 0; i < n; i++)//����
        {
            cout<< a[i].sta <<" "<< a[i].end << endl;
        }*/
    }
    return 0;
}

