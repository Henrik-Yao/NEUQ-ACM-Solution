#include <bits/stdc++.h>
using namespace std;
string unpack()
{
    string tar,s1;
    char ch;//������ʱ�ַ�
    int n;//[���ź�ĵ�һ������
    while(cin>>ch)//ѭ�������ַ���Ctrl+z��
    {
        if(ch=='[')
        {
            cin>>n;
            s1=unpack();//��ʱ��ŵݹ���ַ���
            for(int i=0;i<n;i++)
            tar+=s1;//tarΪ����ÿ�εݹ������
        }
        else
        {
            if(ch==']')
            return tar;
            else
            tar+=ch;
        }
    }
}
int main()
{
    cout<<unpack();
    return 0;
}