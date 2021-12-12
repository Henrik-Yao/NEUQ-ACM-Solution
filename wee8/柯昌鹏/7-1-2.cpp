#include <iostream>
#include <algorithm>
using namespace std;

struct aa{
    int s;
    int t;
};

bool judge (aa f,aa se)//
{
   return f.t<se.t;
}

int main ()
{
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        aa str[n];
        for(int i=0;i<n;i++)
        {
            cin>>str[i].s>>str[i].t;
        }
        sort(str,str+n,judge);//judge是对结构体定义的一个排序条件
        int j=0;
        int res=1;
        for(int i=1;i<n;i++)
        {
            if(str[j].t<=str[i].s)
            {
            j=i;
            res++;
            } 
        }
        cout<<n-res<<endl;
    }
    return 0;
}