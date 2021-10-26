#include <iostream>
#include <map>
using namespace std;
int e[10001][2];
int main()
{
    int n_city,n_road;
	bool flag=false;
    map<int,int> m;
    cin>>n_city>>n_road;
    for(int i=0; i<n_road; i++)
    {
        cin>>e[i][0]>>e[i][1];
    }
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        flag=false;
        for(int j=0; j<n_road; j++)
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
        for(int j=0; j<n_road; j++)
        {
            if(m[e[j][0]]==1&&m[e[j][1]]==1)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
        	cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
