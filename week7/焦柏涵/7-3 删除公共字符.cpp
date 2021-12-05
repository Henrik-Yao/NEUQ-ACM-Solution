#include <bits/stdc++.h>
using namespace std;
int main()
{
	string te; 
	while(getline(cin,te))//包含多组测试！！！！！！！！ 
	{//getline(cin,te);有空格输入 
		string de,miwen="";
		getline(cin,de);
		map<char,int>mp;//放在循环里 
		for(size_t i=0;i<de.length();i++)
		{
			mp.insert(pair<char,int>(de[i],1));//将需要删除的字符与1相匹配 
		}
		for(size_t i=0;i<te.length();i++)
		{
			//if(mp.find(te[i])==mp.end()) cout<<te[i];
			if(mp.find(te[i])!=mp.end()&&mp[te[i]]>0) continue;
			miwen+=te[i];
		}
		cout<<miwen<<endl; 
	}
	return 0;
}
