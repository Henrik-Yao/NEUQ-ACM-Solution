#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
stack <char> s1;
stack <int> s2;
int main()
{
//    freopen("read2.in","r",stdin);
//    freopen("cmp.out","w",stdout);
    string data;
    cin>>data;
    int cnt = 0;
    string now[999];
    for(int i=0;i<data.length();i++)
    {
        if(data[i]=='[')
        {
            cnt++;
            s1.push(data[i]);
            int num = 0;
            i++;
            while(data[i]>='0'&&data[i]<='9')
            {
//				cout<<data[i]<<" ";
				num = num*10+data[i]-'0';
            	i++;
			}
            i--;
            s2.push(num);
        }
        else if(data[i]==']')
        {
            int many = s2.top();
            s2.pop();
            s1.pop();
            while(many--)
            {
                now[cnt-1]+=now[cnt];
//            	cout<<cnt<<":"<<now[cnt]<<endl;
//            	cout<<cnt-1<<":"<<now[cnt-1]<<endl;
			}
            now[cnt].clear();
            cnt--;
        }
        else if(s1.empty())
        {
            now[cnt]+=data[i];
        }
        else if(!s1.empty())
        {
            now[cnt]+=data[i];
        }
    }
    cout<<now[0];


}
