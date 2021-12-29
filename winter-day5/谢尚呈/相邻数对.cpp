#include<iostream>
using namespace std;
int list[1001];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)  cin>>list[i];
    int total=0;
    for(int i=0; i<n-1; i++)
    for(int j=i+1; j<n; j++)
        if(list[i]==list[j]+1||list[i]==list[j]-1)
            total+=1;
    cout<<total;
    return 0;
}
