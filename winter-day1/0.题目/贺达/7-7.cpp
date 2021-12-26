#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,len = 0;
    int min = 0,max = 0,d;//d表示括号后的第一位
    string str;
    getline(cin ,str);
    for(i = 0 ;str[i] != '#';i++)
    {
        len++;//长度统计
    }
    for(i = 0 ;i < len;i++)
    {
       if(str[i] == '(')
       {
        min = i;
       }
       else if(str[i] == ')')
       {
        max = i;
       }
    }
    for(i = 0 ;i < len;i++){
        if(str[i] == 'A'){
            cout << "sae";
        }else if(str[i] == 'B'){
            cout << "tsaedsae";
        }else if(str[i] == '('){
           cout << str[i+1];
           for(d = max - 1;d>min + 1;d--)//逆向输出
           {
            cout << str[d];
            cout << str[i+1];
           }
           i = max;//从右括号开始继续
        }

    }
    return 0;
}

