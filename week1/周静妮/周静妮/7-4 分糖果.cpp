#include <iostream>
using namespace std;
int sum(int n)
{
	int i,t=1;
    for(i=1;i<n;i++)
      if(n%i==0) t+=sum(i);
    return t;
}
int main()
{
    int n;
    cin>>n;
    cout<<sum(n);
    return 0;
}
