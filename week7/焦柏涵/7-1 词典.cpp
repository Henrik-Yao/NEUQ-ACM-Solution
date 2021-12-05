#include <bits/stdc++.h>
using namespace std;
/*struct cidian{
	string en;
	string on;
} cd[10001];*/
map <string,string> mp;//建立mp存储数据 
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string en,on;//en指英文单词，on是外来词汇 
		cin>>en>>on;
		mp.insert(pair<string, string>(on,en));//存入数据，on在前 
	}
	while(m--)
	{
		string cha,jie;//cha是要查询的外来词汇，jie是找到的对应英文词汇 
		cin>>cha;
		if(mp.find(cha)==mp.end()) cout<<"eh"<<endl;
		else
		{
			jie=mp.find(cha)->second;
			cout<<jie<<endl;
		}
	}
}
