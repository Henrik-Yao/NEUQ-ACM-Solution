#include<bits/stdc++.h>
using namespace std;
int a[1000005];//��¼ÿһ��Ĳ���
//��ʾ��Ҫ�Ƚϵ���õ�ľ���+�õ����ܵ������Զ������ܵó����Ž�
int main()
{
    int n,x,s=1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int i = 1;
    while(i + a[i] < n)
    {
        x = 0; x = 0;
        for (int j = 1; j <= a[i]; j++)//������������Զ���ĵ�
        {
            if(j==1) x = 1;//��ʼ��
            if (j+a[i + j] > x+a[i + x]) x = j;//���������Զ�ĵ�
        }
        i += x;//������λ��
        s++;//����һλ
    }
    cout << s;
    return 0;
}

