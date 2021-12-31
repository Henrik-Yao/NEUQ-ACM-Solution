#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N = 1010;
int passwd[N][5];
string realpass[N];
int account = 1;
map <string, int> m;
void get_hash(string pass, string usr)
{
    int len = pass.length();
    int mod = len%4;
    int pass_len[5] = {0};
    for(int i=1;i<=4;i++)
    {
        pass_len[i] = len/4;
        if(i<=mod) pass_len[i]++;
        // cout<<pass_len[i]<<endl;
    }
    // string hashval;
    int j = 0, count = 0;
    for(int i=1;i<=4;i++)
    {
        int tot = 0;
        for(count=count+pass_len[i-1],j=count;j<count+pass_len[i];j++)
        {
            if(pass[j]>='0'&&pass[j]<='9') tot+=pass[j]-'0';
            else if(pass[j]>='a'&&pass[j]<='z') tot+=10+pass[j]-'a';
            else if(pass[j]>='A'&&pass[j]<='Z') tot+=10+pass[j]-'A';
        }
        // cout<<tot<<endl;
        passwd[m[usr]][i] = tot%36;
    }

    // for(int i=1;i<=4;i++)
    // {
    //     cout<<passwd[m[usr]][i]<<" ";
    // }
    // cout<<endl<<endl;
}


bool valid(string login_usr, string pass)
{
    int len = pass.length();
    int mod = len%4;
    int pass_len[5] = {0};
    for(int i=1;i<=4;i++)
    {
        pass_len[i] = len/4;
        if(i<=mod) pass_len[i]++;
        // cout<<pass_len[i]<<endl;
    }
    int j = 0, count = 0;
    for(int i=1;i<=4;i++)
    {
        int tot = 0;
        for(count=count+pass_len[i-1],j=count;j<count+pass_len[i];j++)
        {
            if(pass[j]>='0'&&pass[j]<='9') tot+=pass[j]-'0';
            else if(pass[j]>='a'&&pass[j]<='z') tot+=10+pass[j]-'a';
            else if(pass[j]>='A'&&pass[j]<='Z') tot+=10+pass[j]-'A';
        }
        // cout<<tot<<endl;
        if(passwd[m[login_usr]][i] != tot%36)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    // freopen("read.in","r",stdin);

    int op = read();
    
    while(op--)
    {
        char c;
        cin>>c;
        string username,passwood;
        cin>>username;
        if(c=='R')
        {
            if(m.count(username))
            {
                printf("Repeated!\n");
                cin>>passwood;
                continue;
            }
            else
            {
                m[username] = account;
                cin>>realpass[account];
                get_hash(realpass[account],username);
                account++;
                printf("Signed!\n");
            }
            
        }
        else if(c=='L')
        {
            cin>>passwood;
            if(!m.count(username))
            {
                printf("Failed!\n");
                continue;
            }
            else
            {
                if(valid(username,passwood))
                {
                    if(passwood==realpass[m[username]])
                    {
                        printf("Success!\n");
                    }
                    else
                    {
                        printf("Attention!\n");
                    }
                }
                else{printf("Failed!\n");}
            }
            
        }

    }
}