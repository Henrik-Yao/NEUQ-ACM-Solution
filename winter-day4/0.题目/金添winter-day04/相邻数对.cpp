#include <bits/stdc++.h>
using namespace std;
int a[2000];
int num;
int sum=0;
void search(int n)
{
    for(int i=n+1;i<num;i++)
    {
        if(abs(a[i]-a[n])==1)
        {
            sum++;
        }
    }
    return;
}
int main()
{
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<num;i++)
    search(i);
    cout<<sum<<endl;

    return 0;
}