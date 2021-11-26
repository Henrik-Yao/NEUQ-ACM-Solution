#include<iostream>
#include<cstring>
using namespace std;
int nnext[1000001];
int main()
{
    string text,pattern;
    cin>>text>>pattern;
    nnext[0]=-1;
    int i=-1,j=0,count=0;
    int lenp=pattern.length();
    int lent=text.length();
    while(j<lenp)
    {
        if(i==-1 || pattern[i]==pattern[j])
        {
            i++;
            j++;
            nnext[j]=i;
        }
        else
            i=nnext[i];
    }
    i=0;j=0;
    while(i<lent && j<lenp)
    {
        if(text[i]==pattern[j] || j==-1)
        {
            j++;
            i++;
        }
        else
        {
            j=nnext[j];
        }
        if(j==lenp)
        {
            count++;
            j=nnext[j-1];
            i--;
        }
    }
    cout<<count;
    return 0;
}