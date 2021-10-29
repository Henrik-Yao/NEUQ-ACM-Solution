#include <bits/stdc++.h>
using namespace std;
struct mm
{
    int dir;
    char name[5];
}club[100000];
int main(void)
{
	int m, n, d, s, x=0;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>club[i].dir>>club[i].name;
	
    for(int i=0; i<m; i++)
    {
        cin>>d>>s;
        int bo=(club[x].dir+d)%2;
        if(bo==1)
            x+=s;
        if(bo==0)
            x-=s;
        
        if(x<0)
            x+=n;
        else if(x+1>n)
            x-=n;
    }
    cout<<club[x].name;
    
	return 0;
}