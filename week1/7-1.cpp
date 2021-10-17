#include <iostream>
#include <string>
using namespace std;
string mode[21];
int main(){
    string str;
    int n,num=0;
    cin>>n>>str;
    for(int i=0;i<n;i++)
    {
        cin>>mode[i];
    }
    string b="";
    for(int m=0;m<n;m++){
    for(int j=0;j<str.length();j++)
    {
        if(str[j]==mode[m][0]) {
            for(int i=0;i<mode[m].length();i++)
            {
                b+=str[i+j];
            }
            if(b==mode[m]) {
                num++;
                }
             b="";
    }
        else continue;
    }
    if(m!=n-1) cout<<num<<endl;
        else cout<<num;
    num=0;
    b="";
    }
    return 0;
}
