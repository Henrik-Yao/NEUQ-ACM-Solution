#include<iostream>
#include<cstring>
#include<vector> 
using namespace std;
vector <int> m[5005];
int n,start,flag=0,temp;
void dfs(int i)
{
    if(i<0 || i>=n || m[i][1]==1) return ;
    if(m[i][0]==0)
    {
        flag=1;
        return ;
    }
    m[i][1]=1;
    dfs(i+m[i][0]);
    dfs(i-m[i][0]);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        {
        	cin>>temp;
        	m[i].push_back(temp);
        }
    cin>>start;
    dfs(start);
    if(flag==1) cout<<"True";
    else cout<<"False";
    return 0;
}
