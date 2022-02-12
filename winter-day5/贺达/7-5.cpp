#include<bits/stdc++.h>
using namespace std;

struct people
{
    char sex;
    string father;
};

map<string,people> mp;

int judge(string a,string b)
{
    int i,j;
    i=1;
    for(string A=a;!A.empty();A = mp[A].father,i++)
    {
        j=1;//开始分别比较
        for(string B = b;!B.empty();B = mp[B].father,j++)
        {
            if(i>=5&&j>=5)  return 1;//已经超过五代，满足条件
            if(A==B&&(i<5||j<5))  return 0;//五代内找到共同祖先。
        }
    }
    return 1; //无共同祖先,满足要求
}

int main()
{
    int n;
    cin>>n;
    string a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(b.back() == 'r')//维京女
        {
            mp[a] = {'f',b.substr(0,b.size()-7)};//父亲名字是女生的姓，去掉"sdottir"

        }
        else if(b.back() == 'n')//维京男
        {
            mp[a] = {'m',b.substr(0,b.size()-4)};//去掉"sson"
        }
        else
        {
            mp[a].sex = b.back();
        }
    }

    int m;
    cin>>m;
    string s;
    for(int i=0;i<m;i++)
    {
        cin>>a>>s>>b>>s;
        if(mp.find(a) == mp.end()||mp.find(b) == mp.end())//看是否有人不在名单里
            cout<<"NA"<<endl;
        else if(mp[a].sex == mp[b].sex)  //看是否同性
            cout<<"Whatever"<<endl;
        else
        {
            if(judge(a,b))
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
}
