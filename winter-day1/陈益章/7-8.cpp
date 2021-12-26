#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
stack <char> Q;
char s[11000];
int main()
{
    int T,i;
    Q.push('#');
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int len=strlen(s);
            for(i=0;i<len;i++)
            {
                if(s[i]!='['&&s[i]!='('&&s[i]!=']'&&s[i]!=')'&&s[i]!='{'&&s[i]!='}')
                    continue;
                if(s[i]=='[' || s[i]=='('||s[i]=='{')
                    Q.push(s[i]);
                else if((s[i]==']' && Q.top()=='[') || (s[i]==')' && Q.top()=='(')||(s[i]=='}' && Q.top()=='{'))
                    Q.pop();
                else
                    Q.push(s[i]);
            }
            if(Q.top()=='#')
                printf("Yes\n");
            else
                printf("No\n");
            while(Q.top()!='#')
                Q.pop();
        
    }
    return 0;
}
