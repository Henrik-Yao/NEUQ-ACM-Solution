#include<bits/stdc++.h>

#include <iostream>
#include <algorithm>
using namespace std;
char a[10];
int n;
int main ()
{   cin>>a;
    n=strlen(a);
    sort(a,a+n);
    do
    {
        for (int i = 0 ; i < n ; i++ )
		{
        cout << a[i];
        }
		cout<<endl;
    }while(next_permutation(a,a+n));
    return 0;
}
