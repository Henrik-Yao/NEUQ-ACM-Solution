#include <bits/stdc++.h>
using namespace std;
/*struct cidian{
	string en;
	string on;
} cd[10001];*/
map <string,string> mp;//����mp�洢���� 
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string en,on;//enָӢ�ĵ��ʣ�on�������ʻ� 
		cin>>en>>on;
		mp.insert(pair<string, string>(on,en));//�������ݣ�on��ǰ 
	}
	while(m--)
	{
		string cha,jie;//cha��Ҫ��ѯ�������ʻ㣬jie���ҵ��Ķ�ӦӢ�Ĵʻ� 
		cin>>cha;
		if(mp.find(cha)==mp.end()) cout<<"eh"<<endl;
		else
		{
			jie=mp.find(cha)->second;
			cout<<jie<<endl;
		}
	}
}
