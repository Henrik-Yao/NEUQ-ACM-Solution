#include <bits/stdc++.h>
using  namespace  std;

int main()
{
   int t1,t2;
   string t;
    while (cin>>t)
    {
        t1 = t2 = 0;
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i]=='(')t1++;
            else {
                if(t1==0)t2++;
                else t1--;
            }
        }
        if(t1==0&&t2==0)cout<<"Match"<<endl;
        else {
            cout<<t1+t2<<endl;
            for(int j = 0; j < t2; j++)cout<<"(";
            cout<<t;
            for(int j = 0; j < t1; j++)cout<<")";
            cout<<endl;
        }
    }

    return  0;
}