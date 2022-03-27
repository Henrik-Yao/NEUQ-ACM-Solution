#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>num;
vector<int>num1;
vector<int>num2;
int main()
{
    int x;
    while(cin>>x)
    {
        num.push_back(x);
    }
    sort(num.begin(),num.end());
    for(int i=0;i<num.size();i++)
    {
        if(num[i]%2==0) num2.push_back(num[i]);
        else num1.push_back(num[i]);
        cout<<num[i];
        if(i!=num.size()-1) cout<<"->";
    }
    cout<<"\n";
    for(int i=0;i<num1.size();i++)
    {
        cout<<num1[i];
        if(i!=num1.size()-1) cout<<"->";
    }
    cout<<"\n";
    for(int i=0;i<num2.size();i++)
    {
        cout<<num2[i];
        if(i!=num2.size()-1) cout<<"->";
    }
    return 0;
}