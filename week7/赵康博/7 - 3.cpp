#include <bits/stdc++.h>
using namespace std;
#define N 100
int m[N];
int main(){
    string s1,s2;
    while(getline(cin,s1)&&getline(cin,s2))
    {
        for(int i = 0; i < s2.size(); i++)
        {
            int a = 0,b = 0;
            while(1)
            {
                a = s1.find(s2[i],b);
                if(a>=s2.size())break;
                m[a] = 1;
                b = a + 1;
            }
        }
        for(int i = 0; i < s1.size(); i++)
        {
            if(!m[i])cout<<s1[i];
        }
        memset(m,0,sizeof(m));
    }
    system("pause");
    return 0;
}