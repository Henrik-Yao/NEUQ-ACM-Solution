#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string,string>id_password;
map<string,long long>id_hash;

int to36(char i)
{
    if(i<='9') return i-'0';
    else if(i>='A' && i<='Z') return 10+i-'A';
    else return 10+i-'a';
}

int transform(string str)
{
    int len=str.length();
    int l[5],i,left=len%4;
    for(i=1;i<=4;i++)
    {
        if(left>0) l[i]=len/4+1;
        else l[i]=len/4;
        left--;
    }
    int re=0;
    i=0,len=0;
    for(int j=1;j<=4;j++)
    {
        len=len+l[j];
        int add=0;
        while(i<len)
        {
            add=add+to36(str[i]);
            i++;
        }
        add=add%36;
        re=re*100+add;
    }
    return re;
}

int main()
{
    string op,id,password;
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>op>>id>>password;
        if(op=="R")
        {
            if(id_hash[id]) cout<<"Repeated!\n";
            else
            {
                id_password[id]=password;
                id_hash[id]=transform(password);
                cout<<"Signed!\n";
            }
        }
        else if(op=="L")
        {
            int hash=transform(password);
            if(id_hash[id]==hash && id_password[id]==password) cout<<"Success!\n";
            else if(id_hash[id]==hash) cout<<"Attention!\n";
            else cout<<"Failed!\n";
        }
    }
    return 0;
}