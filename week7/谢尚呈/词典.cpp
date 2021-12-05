#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string dicat[2][10000];
string orgin;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) cin>>dicat[1][i]>>dicat[0][i];
    for(int i=0; i<m; i++)
    {
        orgin="\0";
        cin>>orgin;
        bool it=false;
        for(int j=0; j<n; j++)
           if(dicat[0][j]==orgin)
           {
               it=true;
               orgin=dicat[1][j];
           }
        if(it==false)   orgin="eh";
        cout<<orgin<<endl;
    }
    return 0;
}
