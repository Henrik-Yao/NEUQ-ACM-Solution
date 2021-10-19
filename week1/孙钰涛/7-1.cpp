#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        int count=0;
        int len_s=s.length();
        int len_a=a.length();

        for(int j=0;j<len_s;j++)
        {
            int flag=1;
            for(int k=0;k<len_a;k++)
            {
                if(s[j+k]!=a[k])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1) count++;
        }
        cout<<count;
        if(i!=n) cout<<"\n";
    }
    return 0;
}