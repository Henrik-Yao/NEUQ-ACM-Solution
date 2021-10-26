#include <iostream>
using namespace std;

void move(int n,string start,string pass,string end);

int main()
{
    int n;
    string start,pass,end;
    cin>>n>>start>>pass>>end;
    move(n,start,pass,end);
    
}

void move(int n,string start,string pass,string end)
{
    if(n==0)
        return;
    move(n-1,start,end,pass);
    cout<<start<<"->"<<end<<endl;
    move(n-1,pass,start,end);
}

