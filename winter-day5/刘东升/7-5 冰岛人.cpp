#include<bits/stdc++.h>
using namespace std;

struct people
{
    char sex;
    string father;
};

map<string,people> mp;

int judge(string a,string b)
{
    int i,j;
    i=1;
    for(string A=a;!A.empty();A = mp[A].father,i++)
    {
        j=1;//��ʼ�ֱ�Ƚ�
        for(string B = b;!B.empty();B = mp[B].father,j++)
        {
            if(i>=5&&j>=5)  return 1;//�Ѿ������������������
            if(A==B&&(i<5||j<5))  return 0;//������ҵ���ͬ���ȡ�
        }
    }
    return 1; //�޹�ͬ����,����Ҫ��
}

int main()
{
    int n;
    cin>>n;
    string a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(b.back() == 'r')//ά��Ů
        {
            mp[a] = {'f',b.substr(0,b.size()-7)};//����������Ů�����գ�ȥ��"sdottir"

        }
        else if(b.back() == 'n')//ά����
        {
            mp[a] = {'m',b.substr(0,b.size()-4)};//ȥ��"sson"
        }
        else
        {
            mp[a].sex = b.back();
        }
    }

    int m;
    cin>>m;
    string s;
    for(int i=0;i<m;i++)
    {
        cin>>a>>s>>b>>s;
        if(mp.find(a) == mp.end()||mp.find(b) == mp.end())//���Ƿ����˲���������
            cout<<"NA"<<endl;
        else if(mp[a].sex == mp[b].sex)  //���Ƿ�ͬ��
            cout<<"Whatever"<<endl;
        else
        {
            if(judge(a,b))
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
}
