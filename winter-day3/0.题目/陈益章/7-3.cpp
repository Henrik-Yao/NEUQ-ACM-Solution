#include<set>                                     
#include<cstring>
#include<vector>
using namespace std;
int n,a[20],ans=0;
bool flag[20];
vector<int>res;
set<string>s;

void judge()
{                                           
    if(res.size()<=1) return ;
    for(int i=1;i<res.size();i++)
        if(res[i]<res[i-1]) return ;
    string str="";                        
    for(int i=0;i<res.size();i++)
        str=str+char('0'+res[i]);
    s.insert(str);
    return ;                                                                         
}

void enumerate(int i)
{
    if(i==n+1)                                                                       
    {
        judge();
        return ;
    }                 
    res.push_back(a[i]);
    enumerate(i+1);
    res.pop_back();
    enumerate(i+1);                  
}
                                                  
int main()
{
    memset(flag,0,sizeof(flag));
    cin>>n;
    for(int i=1;i<=n;i++)                       
        cin>>a[i];
    enumerate(1);
    cout<<s.size();
}               
