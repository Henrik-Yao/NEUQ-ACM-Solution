#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[12];
    cin>>a;

    int n = strlen(a);
    sort(a,a+n);

    do{

        for(int i=0;i<n;i++)
            cout<<a[i];
        cout<<endl;
    }while(next_permutation(a,a+n));


	return 0;
}
