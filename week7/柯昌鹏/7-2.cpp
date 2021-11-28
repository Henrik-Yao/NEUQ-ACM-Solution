#include <bits/stdc++.h>
using namespace std;

string trs()//建议用一个样例来理解，也可以去洛谷看看更详细的解答
{
   string a="",b="";
   int k;
   char ch;
   while(cin>>ch)
   {
      if(ch=='[')//一个解码过程
      {
         cin>>k;
         b=trs();
         while(k--)//解码的过程
         {
            a+=b;
         }
      }
      else if(ch==']')
      {
         return a;//返回这一层的解码结果
      }
      else//接受中间字符 
      {
         a+=ch;
      }
   }
}

int main ()
{
   cout<<trs();
   return 0;
}