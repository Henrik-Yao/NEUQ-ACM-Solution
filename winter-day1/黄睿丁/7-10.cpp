#include <queue>
#include <iostream>
#include <vector>
using namespace std;
vector<int>rail[100];
int a[100];
int main()
{
    int n;
    cin>>n;
    int i,j,l,m=-1;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        j=1;
        while(1)
        {
            if(rail[j].empty()||rail[j].back()>a[i])
            {
                rail[j].push_back(a[i]);
                m=max(m,j);
                if(a[i]==1)
                    l=j;
                break;
            }
            j++;
        }
    }
    vector<int>::iterator s;
    for(s=rail[l].begin();s<rail[l].end()-1;s++)
        cout<<*s<<" ";
    cout<<*s;
    cout<<endl<<m;
    
}
