#include <iostream>//感觉这题就是一个map的使用教程。。
#include <map>
using namespace std;

map<string ,string >m;

int main()
{
    int dic,trs;
    string f,t;
    cin>>dic>>trs;
    while(dic--)
    {
        cin>>f>>t;
        m.insert(pair<string ,string >(t,f));
    }
    string ff;
    while(trs--)
    {
        cin>>ff;
        map<string ,string >::iterator pos=m.find(ff);
        if(pos!=m.end())
        {
            cout<<pos->second<<endl;
        }
        else cout<<"eh"<<endl;
    }
    return 0;
}

