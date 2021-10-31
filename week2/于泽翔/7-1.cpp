#include <bits/stdc++.h>
using namespace std;
string a, b, c;
void move(int n, string z1, string z2, string z3)
{
    if(n==1)
        cout<<z1<<"->"<<z3<<endl;
    else
    {
        move(n-1, z1, z3, z2);
        cout<<z1<<"->"<<z3<<endl;
        move(n-1, z2, z1, z3);
    }
}
int main(void)
{
    int n;
    cin>>n>>a>>b>>c;
    move(n, a, b, c);
    
    return 0;
}