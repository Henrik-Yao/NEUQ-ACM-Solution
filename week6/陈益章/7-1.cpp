#include<iostream>
#include<cstring>
using namespace std;
int nex[1000001];
int main()
{
    string text,pattern;
    cin>>text>>pattern;
    nex[0]=-1;
    int i=-1,j=0,sum=0;
    int lenp=pattern.length();
    int lent=text.length();
    while(j<lenp)
    {
        if(i==-1 || pattern[i]==pattern[j])
        {
            i++;
            j++;
            nex[j]=i;
        }
        else
            i=nex[i];
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
            j=nex[j];
        }
        if(j==lenp)
        {
            sum++;
            j=nex[j-1];
            i--;
        }
    }
    cout<<sum;
}
