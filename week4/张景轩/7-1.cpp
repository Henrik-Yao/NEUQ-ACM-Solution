#include<iostream>
using namespace std;

bool isPrime(int a)
{
    if(a == 1)
    {
        return false;
    }
    else if(a == 2)
    {
        return true;
    }
    else
    {
        for(int i=2;i<=a/2;i++)
        {
            if(a % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    int max,min;
    while(cin>>min)
    {
        cin>>max;
        int a[100000];
        int n=0;
        for(int i=min;i<=max;i++)
        {
            if(isPrime(i))
            {
                a[n] = i;
                n++;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i];
            if(i<n-1)
            {
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}