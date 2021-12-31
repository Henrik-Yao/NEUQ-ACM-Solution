#include <bits/stdc++.h>
using namespace std;
bool mod(int a)
{
    if (a % 2)
        return false;
    else
        return true;
}
int a[100000], b[100000], c[100000];
int main()
{
    int l = 0;
    int num1 = 0, num2 = 0;
    while (cin >> a[l])
    {
        if (mod(a[l]))
        {
            b[num1] = a[l];
            num1++; //Å¼Êý
        }
        else
        {
            c[num2] = a[l];
            num2++; //ÆæÊý
        }
        l++;
    }
    sort(a, a + l);
    for (int i = 0; i < l; i++)
    {
        if(i==0)
        cout<<a[i];
        else
        cout<<"->"<<a[i];
    }
    cout<<endl;
    sort(b, b + num1);
    sort(c, c + num2);

    for (int i = 0; i < num2; i++)
    {
        if(i==0)
        cout<<c[i];
        else
        cout<<"->"<<c[i];
    }
    cout<<endl;
    for (int i = 0; i < num1; i++)
    {
        if(i==0)
        cout<<b[i];
        else
        cout<<"->"<<b[i];
    }
    return 0;
}