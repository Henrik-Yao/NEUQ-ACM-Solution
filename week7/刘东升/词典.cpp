#include<bits/stdc++.h>
using namespace std;
const int M=10000;
string library[2][M];
string partten;
int main()
{
    int n,m,i,j;cin>>n>>m;
    for(i=0;i<n; i++)
	{
		cin>>library[1][i]>>library[0][i];
	}
    for(int i=0;i<m;i++)
    {

        cin>>partten;
        bool judge=false;
        for(j=0;j<n;j++)
           if(library[0][j]==partten)
           {
               judge=true;
               partten=library[1][j];
           }
        if(judge==false)
		{
			partten="eh";
		}
        cout<<partten<<endl;
    }
}
