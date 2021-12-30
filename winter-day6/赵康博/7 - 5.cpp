#include <bits/stdc++.h>
using namespace std;
#define N 100
int s[N];
int n;
void print()
{
    for (int i = 0; i < n; i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void temp(int a,int b)
{
    int t;
    t = s[a];
    s[a] = s[b];
    s[b] = t;
}
void MaxD(int n){
    for (int i = (n+1)/2 - 1; i >= 0; i--)
    {
            int f = i;
            int z = 2*f + 1;
            if(z+1<n&&s[z]<s[z+1])z ++;
                while (s[f]<s[z]&&z < n)
                {
                    temp(f,z);
                    f = z;
                    z = 2*f + 1;
                    if(z+1<n&&s[z]<s[z+1])z ++;
                }
    }
    
}
void p(){
    int a = n;
    while (a!=0)
    {
        MaxD(a);
        print();
        temp(0,a-1);
        a--;
    }
}
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    p();
    return 0;
}