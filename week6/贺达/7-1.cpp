#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int ne[1000004];

void get_next(string t)
{
    int i=0;
    ne[0]=-1;
    int j=-1;
    int lt=t.length();
    while(i<lt)
    {
        if(j==-1||t[i]==t[j])
        {
            i++;
            j++;
            ne[i]=j;
        }
        else
        {
            j=ne[j];
        }
    }
}

void kmp(string s,string t)
{
    int i=-1;
    int j=-1;
    int ls=s.length();
    int lt=t.length();
    while(i<ls)
    {
        if(j==-1||s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            j=ne[j];
        }
        //cout<<j<<endl;
        if(j==lt)
        {
            cnt++;

        }

    }
}


int main()
{
    string s,t;
    cin>>s;
    cin>>t;

    get_next(t);
    kmp(s,t);
    int lt=t.length();
    //for(int i=0;i<lt+2;i++)
    //{
      //  cout<<ne[i]<<" ";
    //}
    //cout<<endl;
    cout<<cnt;
    return 0;
}
