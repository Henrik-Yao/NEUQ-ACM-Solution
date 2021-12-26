#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        int num1 = 0, num2 = 0; // num1为（,num2为）
        stack<char> mystack;
        int len = str.size();
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '(')
            {
                mystack.push('('); //前括号无条件入栈
                num1++;
            }

            else if (str[i] == ')')
            {
                if (!mystack.empty()&&mystack.top() == '(')
                {
                    mystack.pop(); //若匹配成功，则将其出栈
                    num1--;
                }
                else
                {
                    num2++;
                    mystack.push(')'); //将其输入
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