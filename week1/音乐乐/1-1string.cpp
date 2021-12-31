#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    string s;
    cin>>s;
    int len=s.size();
    while(n--)
    {
        int ans=0;
        string s1;
        cin>>s1;
        int len1=s1.size();
        for(i=0;i<=len-len1;i++)
        {
            if(s[i]==s1[0])
            {
                bool flag=1;
                int j,k=0;
                for(j=i;j<i+len1;j++)
                {
                    if(s[j]!=s1[k++])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
