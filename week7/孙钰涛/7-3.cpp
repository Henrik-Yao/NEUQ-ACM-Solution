#include<iostream>
#include<map>
#include<string>
using namespace std;

map<char,string>dele;
int main()
{
    string text,a;
    while(getline(cin,text) && getline(cin,a))
    {
        int lent=text.size();
        int lena=a.size();
        for(int i=0;i<lena;i++)
        {
            dele[a[i]]="666";
        }
        for(int i=0;i<lent;i++)
        {
            if(dele[text[i]]!="666") cout<<text[i];
        }
        cout<<"\n";
        dele.clear();
    }
    return 0;
}