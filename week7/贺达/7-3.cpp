#include<bits/stdc++.h>
using namespace std;
//vector<char>v1;
//vector<char>v2;
#define M 100100
char m[M];
char n[M];

int main()
{
    char c;
    while(cin>>c)
    {
        m[0]=c;
        int lm=1;
        int ln=0;
        while(scanf("%c",&m[lm]),m[lm]!='\n')
       {
          lm++;
       }
       m[lm]='\0';

       while(scanf("%c",&n[ln]),n[ln]!='\n')
       {
          ln++;
       }
       n[ln]='\0';
         for(int i=0;i<lm;i++)
        {
          int p=0;
          for(int j=0;j<ln;j++)
            {
             if(m[i]==n[j])
              {
                  p=1;
              }
            }
             if(p==0)
            {
              cout<<m[i];
            }
        }
        cout<<endl;
    }

    return 0;
}
