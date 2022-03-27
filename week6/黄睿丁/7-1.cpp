#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;
char text[1000001],pattern[1000001];
int table[1000001]={-1};
void check(int len)
{
    int k=-1,j=0;
    while(j<len)
    {
        if(k==-1||pattern[k]==pattern[j])
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
int main()
{
    cin>>text;
    cin>>pattern;
    int a=strlen(text),b=strlen(pattern);
    check(b);
    int x=0,y=0,sum=0,i;
    while(y<a)
    {
        if(x==-1||text[y]==pattern[x])
        {
            x++;
            y++;
            
        }
        else
        {
            x=table[x];
        }
        if(x==b)
        {
            sum++;
        }
    }
    cout<<sum;
}

