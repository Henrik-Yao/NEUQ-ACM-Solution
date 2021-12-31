#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int>v1,v2,v3;
int main()
{
    int num;
    while(cin>>num)
	{
		v1.push_back(num);
	}
    sort(v1.begin(),v1.end());
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i];
        if(i<v1.size()-1)
		{
			cout<<"->";
		}
        if(v1[i]%2==1)
		{
			v2.push_back(v1[i]);
		}
        else 
		{
			v3.push_back(v1[i]);
		}
    }
    cout<<endl;
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i];
        if(i<v2.size()-1)
		{
			cout<<"->";
		}
    }
    cout<<endl;
    for(int i=0;i<v3.size();i++)
    {
        cout<<v3[i];
        if(i<v3.size()-1)
		{
			cout<<"->";
		}
    }
    return 0;
}
