#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        int num1 = 0, num2 = 0; // num1Ϊ��,num2Ϊ��
        stack<char> mystack;
        int len = str.size();
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '(')
            {
                mystack.push('('); //ǰ������������ջ
                num1++;
            }

            else if (str[i] == ')')
            {
                if (!mystack.empty()&&mystack.top() == '(')
                {
                    mystack.pop(); //��ƥ��ɹ��������ջ
                    num1--;
                }
                else
                {
                    num2++;
                    mystack.push(')'); //��������
                }
            }
        }
        if (mystack.empty())
            cout << "Match" << endl;
        else
        {
            cout << mystack.size()<<endl;
            for (int i = 0; i < num2; i++)
                cout << '(';
            cout << str;
            for (int i = 0; i < num1; i++)
                cout << ')';
                cout<<endl;
        }
    }
    return 0;
}