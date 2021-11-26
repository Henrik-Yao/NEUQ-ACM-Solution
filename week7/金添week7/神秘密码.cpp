#include <bits/stdc++.h>
using namespace std;
string unpack()
{
    string tar,s1;
    char ch;//输入暂时字符
    int n;//[括号后的第一个数字
    while(cin>>ch)//循环输入字符（Ctrl+z）
    {
        if(ch=='[')
        {
            cin>>n;
            s1=unpack();//暂时存放递归的字符串
            for(int i=0;i<n;i++)
            tar+=s1;//tar为主串每次递归的主串
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