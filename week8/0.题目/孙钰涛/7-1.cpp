#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<int,int>find_begin;
vector<int>e;
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int n,begin,end,Count=1;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>begin>>end;
            if(find_begin[end]==0) find_begin[end]=begin;
            else find_begin[end]=max(find_begin[end],begin);
            e.push_back(end);
        }
        sort(e.begin(),e.end());
        end=e[0];
        for(int j=0;j<n;j++)
        {
            if(find_begin[e[j]]>=end)
            {
                Count++;
                end=e[j];
            }
        }
        cout<<n-Count<<"\n";
        e.clear();
        find_begin.clear();
    }
    return 0;
}