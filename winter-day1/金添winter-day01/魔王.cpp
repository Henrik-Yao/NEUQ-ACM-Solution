#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int len=str.size();
    for(int i=0;i<len;i++)
    {
        if(str[i]=='A')
        cout<<"sae";
        else if(str[i]=='B')
        {
            cout<<"tsaedsae";
        }
        else if(str[i]=='(')
        {
            char head=str[i+1];
            int zan=i+2;int end=0;
            stack<char> word;
            while(str[zan]!=')')
            {
                word.push(str[zan]);
                zan++;
            }
            end=zan;
            while(!word.empty())
            {
                cout<<head<<word.top();
                word.pop();
            }
            cout<<head;
            i=end;
        }
        else if((str[i]<='z'&&str[i]>='a')||(str[i]<='Z'&&str[i]>='A'))
        {
            cout<<str[i];
        }
        
    }
    cout<<endl;
    return 0;
}