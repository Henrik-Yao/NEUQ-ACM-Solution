#include <bits/stdc++.h>
using namespace std;
char a[1000001],b[1000001],c[1000001];
int table[1000001];
char read(char a)
{
    if(a>='A'&&a<='Z')
        return a-'A'+'a';
    else if(a>='a'&&a<='z')
        return a;
    else
        return 0;
}
void check(int len)
{
    int k=-1,j=0;
    while(j<len)
    {
        if(k==-1||b[k]==b[j])
        {
            k++;
            j++;
            table[j]=k;
        }
        else
        {
            k=table[k];
        }
    }
}
int kmp()
{
    
    int len1=strlen(c),len2=strlen(b);
    check(len2);
    int x=0,y=0,i;
    while(y<len1)
    {
        if(x==-1||c[y]==b[x])
        {
            x++;
            y++;
            
        }
        else
        {
            x=table[x];
        }
        if(x==len2)
        {
            return 1;
        }
    }
}


int main()
{
    getline(a);
    getline(b);
    int len=strlen(a),i,j=0,sum=0;
    for(i=0;i<len;i++)
    {
        char x=read(a[i]);
        if(x)
        {
            c[j++]=x;
        }
        else
        {
            sum+=kmp();
            memset(c,0,1000001);
            memset(table,0,1000001);
            j=0;
        }
    }
    cout<<sum;
    
}
