#include<bits/stdc++.h>
using namespace std;
bool ju;
int m[50010],start,length,jud[50010];
void chu(int start)
{
	jud[start]=1;
	if(m[start]==0) 
	{
		ju=1;
		return ;
	}
	if((jud[start+m[start]]||start+m[start]>=length)&&(jud[start-m[start]]||start-m[start]<0)) return ;
	if(start+m[start]<length)
	chu(start+m[start]);
	if(start-m[start]>=0)
	chu(start-m[start]);
	
}
int main()
{
	
	cin>>length;
	for(int i=0;i<length;i++) cin>>m[i];
	cin>>start;
	chu(start);
	if(ju) cout<<"True";
	else cout<<"False";
	return 0;
}