#include <bits/stdc++.h>
using namespace std;
int main()
{
	string te; 
	while(getline(cin,te))//����������ԣ��������������� 
	{//getline(cin,te);�пո����� 
		string de,miwen="";
		getline(cin,de);
		map<char,int>mp;//����ѭ���� 
		for(size_t i=0;i<de.length();i++)
		{
			mp.insert(pair<char,int>(de[i],1));//����Ҫɾ�����ַ���1��ƥ�� 
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
