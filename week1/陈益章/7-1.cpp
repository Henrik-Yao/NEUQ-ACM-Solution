#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,l=0,ls=0,sum=0;
    bool b=0;
    string c,ms;
    cin>>n;
    cin>>c;
    l=c.length();
    if (n==0)
        return 0;
    for (int i=0; i<n; i++)
    {
        cin>>ms;
        ls=ms.length();
        for (int j=0; j<l; j++)
        {
            for (int k=0; k<ls; k++)
            {
                if (c[j+k]!=ms[k])
                {
                    b=0;
                    break;
                }
                else
                    b=1;
            }
            if (b==1)
                sum++;
            b=0;
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}