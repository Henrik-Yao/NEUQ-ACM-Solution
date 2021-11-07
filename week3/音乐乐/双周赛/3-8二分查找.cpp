#include<iostream>
#include<algorithm>
using namespace std;

int N,x,a[100010];
int main()
{
    cin>>N>>x;
    for(int i=0;i<N;i++)
        cin>>a[i];
    sort(a,a+N);
    int j=lower_bound(a,a+N,x)-a;
    if(j==N) cout<<N<<endl;
    else 
	cout<<j+1<<endl;
    return 0;
}

