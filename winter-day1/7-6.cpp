#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int mid=s.length() / 2;
    int flag = true;

    for (int i = 0; i < mid; i++)
    {
        if(s[i] != s[s.length() - 1 - i])
        {
            flag = false;
            break;
        }
    }
    if(flag == true)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout <<"no"<<endl;
    }

    return 0;
}