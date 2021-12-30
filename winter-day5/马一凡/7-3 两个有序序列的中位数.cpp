#include<iostream>
#include <algorithm>
using namespace std;

int a[200100];
int main()
{
    int n;
    cin >> n;
    for(int i=0; i < 2*n; i++){
        cin >> a[i];
    }
    sort(a,a+2*n);
    int sum = (a[n-1]+a[n])/2;
    cout << sum << endl;
    
    
    return 0;
}


