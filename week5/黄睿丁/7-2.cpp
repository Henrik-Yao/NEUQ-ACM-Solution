#include <bits/stdc++.h>
using namespace std;
int judge(int n)
{
    int i,flag=1;
    for(i=2;i<=sqrt(n);i++)
    { 
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
int main()
{
    int m,n,i,j;
    cin>>m;
    for(i=0;i<m;i++)
    {
        int s;
        cin>>n;
        if(n%2==0)
            s=2;
        else
        {
            if(judge(n))
            {
                s=1;
            }
            else
            {
               if(judge(n-2))
			   s=2;
			   else
			   s=3; 
            }
        }
        cout<<s<<endl;
    }
