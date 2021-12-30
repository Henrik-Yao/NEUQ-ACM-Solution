#include <iostream>
#include <algorithm>
#include <stdio.h>
 
using namespace std;
 
const int N = 1000;
int a[N];
 
int main(void)
{
    int n, sum=0;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i]; 
    sort(a, a+n);
    for(int i=1; i<n; i++)
        if(a[i]-a[i-1] == 1)
            sum++;
 
    cout << sum << endl;
 
    return 0;
}
 
