#include <bits/stdc++.h>
using namespace std;
queue<int> railway[1000]; //װ�𳵵Ĺ��
int train[1000];          //���л𳵱��
int main()
{
    int num;
    cin >> num; //����
    for (int i = 0; i < num; i++)
        cin >> train[i];

    int len = 1;
    railway[1].push(train[0]); //��һ�����Ƚ���
    for (int i = 1; i < num; i++)
    {
        int contain = 0;

        for (int j = 1; j <= len; j++)
        {
            if (train[i] < railway[j].back()) //���Ȱѳ��嵽β����Ķ��к���
            {
                if (contain != 0 && railway[contain].back() < railway[j].back())
                    continue; //��������ϣ�����ҵ��Ĺ�������Ÿ���ģ��ٻ�
                contain = j;
            }
        }
        if (contain) //�����ж��д��ڷ���
        {
            railway[contain].push(train[i]);
        }
        else
        {
            railway[++len].push(train[i]);  //�½������
        }
  	}
            while(!railway[1].empty())
            {
            	int temp=railway[1].front();
                railway[1].pop();
                if (!railway[1].empty())
                cout<<temp<<" ";
                else cout<<temp;
            }
            cout<<endl;
     cout<<len<<endl;   
    return 0;
}