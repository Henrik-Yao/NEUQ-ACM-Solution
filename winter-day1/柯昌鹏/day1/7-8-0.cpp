#include <stack>//用stl中的栈来做
#include <iostream>
#include <string>

using namespace std;

string bracketLeft = "{[(";//用于匹配对应的括号
string bracketRight = "}])";

bool judge(string str)
{
    stack<char> s;
    // 遍历字符串
    for (int i = 0; i < str.length(); i++)
    {
        char chr = str[i];
        int indexLeft = -1, indexRight = -1;
        indexLeft = bracketLeft.find(chr);
        indexRight = bracketRight.find(chr);
        // 是左括号
        if (indexLeft >= 0)
            s.push(chr);    // 入栈
        // 是右括号
        else if (indexRight >= 0)
        {
            // 匹配成功
            if (!s.empty() && s.top() == bracketLeft[indexRight])
                s.pop();    // 出栈
            else
                return false;
        }
    }

    return s.empty();//如果最后栈是空的那么就说明匹配成功了
}

int main()
{
    string a;
    cin>>a;
    if(judge(a))
    {
        cout<<"yes"<<endl;
    }
    else cout<<"no"<<endl;
    return 0;
}