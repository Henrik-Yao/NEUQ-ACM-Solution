#include <iostream>
#include <map>
using namespace std;

int e[10001][2];
int main()
{
    int M,N;
    int flag=0;
    map<int,int> m;
    cin>>M>>N;

    for(int i=0; i<N; i++)
    {
        cin>>e[i][0]>>e[i][1];
    }

    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        flag=0;
        for(int j=0; j<N; j++)
        {
            m[e[j][0]]=1;
            m[e[j][1]]=1;
        }
        int num;
        cin>>num;
        for(int j=0; j<num; j++)
        {
            int t;
            cin>>t;
            m[t]=0;
        }
        for(int j=0; j<N; j++)
        {
            if(m[e[j][0]]==1 && m[e[j][1]]==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
