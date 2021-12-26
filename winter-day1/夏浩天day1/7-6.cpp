#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string lsz;cin>>lsz;
    for(int i=0;i<lsz.size()/2;i++)
    {
        if(lsz[i]!=lsz[lsz.size()-i-1])
        {cout<<"no"<<endl;return 0;}
    }
    cout<<"yes"<<endl;
}