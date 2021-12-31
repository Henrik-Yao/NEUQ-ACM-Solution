#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
int main()
{
    char num[9];
    cin>>num;
    int n = strlen(num);
 stable_sort(num,num+n);
 cout<<num<<endl;
 while(next_permutation(num,num+n)){
     for(int i=0;i<n;i++)
      cout<<num[i];
        cout<<endl;}
    return 0;
}
