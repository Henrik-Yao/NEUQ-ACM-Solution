#include <bits/stdc++.h>
using namespace std;

int num = 0;

int di(int a)
{
    if(a==2)
    {
        num += 2;
        return 0;
    }
    else if(a==1)
    num = 1;
    else
    {
        num += 2;
        for(int i=a/2;i>=2;i--)
        {
            if(a%i==0)
                di(i);
        }
    }


}


int main()
{

    int a;
    cin>>a;

    di(a);

    cout<<num;

    return 0;
}
