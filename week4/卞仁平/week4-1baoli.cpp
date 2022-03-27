#include <bits/stdc++.h>
using namespace std;
int main()
{
    //先用暴力筛看看过得了不
    int a,b;
    while(cin>>a>>b)
    {
    int ff=0;
    for(int i=a;i<=b;i++)
    {
        int f=1;
        
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                f=0;
                break;
            }
        }
        if(f)
        {ff++;}
        if(ff==1&&f)
        cout<<i;
        else if(ff>1&&f)
        cout<<" "<<i;
    }
    cout<<endl;
    
    }
}