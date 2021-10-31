#include<iostream>
using namespace std;
struct peo
{
    int tw;
    string name;
};
peo arr[100005];

int main()
{
    int n,m,i,now=1;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i].tw>>arr[i].name;
    }
    while(m--)
    {
        int pos,num;
        cin>>pos>>num;
        if(pos==arr[now].tw)
        {
            now=(now-num+n)%n;
            continue;
        }
        else
        {
            now=(now+num)%n;
            continue;
        }
    }
    cout<<arr[now].name;
    return 0;
}
