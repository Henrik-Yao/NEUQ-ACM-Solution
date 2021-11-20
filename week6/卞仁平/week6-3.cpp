#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
string a,b;
string S[maxn];
int main()
{
    getline(cin,a);
    getline(cin,b);
    //csdn搜到的读入方式，可以读入空格
    int al=a.length();
    int bl=b.length();
    //定义长度

    int f=0;
    int ddl=0;
    for(int i=0;i<bl;i++)
        if(b[i]>='A'&&b[i]<='Z')
        b[i]+=32;
    for(int i=0;i<al;i++)
    {
        if(a[i]<'A'||a[i]>'z'||(a[i]>'Z'&&a[i]<'a'))
        {
            if(f==1)f=0;
        }    
        else 
        {
            if(a[i]>='A'&&a[i]<='Z')
                a[i]+=32;
            if(f==0)
            {
                f=1;
                ddl++;
            }
            S[ddl]+=a[i];//存入符合标准的字符串
        }
    }
    int s=0;
    for(int i=0;i<=ddl;i++)
    {
        if(S[i].find(b)!=-1)
        s++;
    }
    cout<<s;
    return 0;
}