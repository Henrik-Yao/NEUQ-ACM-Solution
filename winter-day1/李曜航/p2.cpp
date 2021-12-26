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
list <char> a;
void print()
{
    for(auto& pr:a)
    {
        cout<<pr;
    }
    cout<<endl<<endl;
}
int main()
{
    freopen("read.in","r",stdin);
    string text;
    getline(cin,text);
    list <char>::iterator p = a.begin();
    bool insert = false;
    for(int i = 0; i < text.size(); i++)
    {
        if(text[i]=='[') p = a.begin();
        else if(text[i]==']') p = a.end();
        else if(text[i]=='{'){ if( p!=a.begin() ){p--;} } 
        else if(text[i]=='}'){ if( p!=a.end() ){p++;} }
        else if(text[i]=='-'){if(insert)insert=false;else insert=true;}//insert = insert^1;
        else if(text[i]=='=')
        {
            // cout<<"1"<<*p<<endl;
            // p--;
            // p--;
            // cout<<"2"<<*p<<endl;
            list <char>::iterator tp = p;
            tp--;
            // cout<<*tp<<endl;
            // tp++;
            // cout<<*tp<<endl;
            // p++;
            a.erase(tp);
        }
        else
        {
            if(!insert)
                a.insert(p,text[i]);
            else
            {
                *p = text[i];
                p++;
            }
        }
        
    }
        print();


}