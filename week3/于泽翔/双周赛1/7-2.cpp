#include <bits/stdc++.h>
using namespace std;
string a, b, c;
void nanoi(int n, string z1, string z2, string z3)
{
    if(n==1)
        cout<<z1<<"->"<<z3<<endl;
    else
    {
        nanoi(n-1, z1, z3, z2);
        cout<<z1<<"->"<<z3<<endl;
        nanoi(n-1, z2, z1, z3);
    }
    return;
}
int main(void)
{
	int n;
    cin>>n>>a>>b>>c;
    
    nanoi(n, a, b, c);
	
	return 0;
}