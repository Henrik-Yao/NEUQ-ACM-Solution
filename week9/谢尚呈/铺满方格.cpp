#include<iostream>
using namespace std;
long long use[51];
int main()
{
    int n;
    use[0]=0;
    use[1]=1;
    use[2]=2;
    use[3]=4;
    while(cin>>n)
    {
    	for(int i=4; i<=n; i++)
		    use[i]=use[i-1]+use[i-2]+use[i-3];
        cout<<use[n]<<endl;
    }
    return 0;
}
