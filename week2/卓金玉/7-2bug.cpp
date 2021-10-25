#include<iostream>
#include<map>
using namespace std;
typedef pair<int,int>apair;
int main()
{
	int n,m,k;
	scanf("%d %d",&n,&m);
	multimap<int,int>Connect;
	int f,l;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&f,&l);
		Connect.insert(apair(f,l));
	}
	scanf("%d",&k);
	while(k)
	{
		k--;
		multimap<int,int>C(Connect.begin(),Connect.end());
		int cityNum,attackCity;
		scanf("%d",&cityNum);
		int nn=cityNum,j=0;
		int attack[nn];
		while(cityNum)
		{
			scanf("%d",&attack[j]);
			C.erase(attack[j]);
			j++;
			cityNum--;
		}
		if(C.empty()) printf("YES\n");
		else
		{
			multimap<int,int>T;
			for(auto ita=C.begin();ita!=C.end();ita++)
			{
				T.insert(apair(ita->second,ita->first));
			}
			for(int i=0;i<nn;i++)
			{
				T.erase(attack[i]);
			}
			if(T.empty()) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
