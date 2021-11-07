#include<iostream>
using namespace std;
char a[30],b[30],c[30];
void move(char a[],char b[])
{
    cout<<a<<"->"<<b<<endl;
}
void hanoi(int n,char a[],char b[],char c[])
{
    if(n==1)
        move(a,c);
    else
    {
        hanoi(n-1,a,c,b);
        move(a,c);
        hanoi(n-1,b,a,c);
    }
}

int main ()
{
    int n;
    cin>>n;
    cin>>a;
    cin>>b;
    cin>>c;
    hanoi(n,a,b,c);
}
