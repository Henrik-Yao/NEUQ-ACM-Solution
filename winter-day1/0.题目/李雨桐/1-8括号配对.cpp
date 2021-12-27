#include <iostream>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    string str;
    cin>>n;
    while (n--)
    {
        cin>>str;
        int len=str.length();
        stack<char> vec;
        for(int i = 0; i < len; i++)
        {
            if(vec.empty()) vec.push(str[i]);
            else if(vec.top()=='[' && str[i]==']') vec.pop();
            else if(vec.top()=='(' && str[i]==')') vec.pop();
            else vec.push(str[i]);
        }
        if(vec.empty()) puts("Yes");
        else puts("No");
    }
    return 0;
}
