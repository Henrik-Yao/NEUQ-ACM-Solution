#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int Next[maxn];
string text,pat;
void next()
{
	int i=0,j=-1;
	Next[0]=-1;
	while(i<pat.size())
	{
		if(j==-1||pat[i]==pat[j])
		{
			i++;
			j++;
			Next[i]=j;
		}//j=-1为刚开始，且是使j自加的条件，s[i]==s[j]时是指结束的部位与前面的第几个相等
		else
		j=Next[j];  //查看已经重复的字符串里是否有可以重复的，如果有，看是否接得上
	}
}
int  kmp()
{
	int ads=0,i=0,j=0;
	while(i<text.size())
	{
		if(j==-1||text[i]==pat[j])
		{
			j++;
			i++;
			
		}
		else j=Next[j];
		if(j==pat.size()) ads++;
	}
	return ads;
}
int main()
{
	cin>>text>>pat;
	next();
	cout<<kmp()<<'\n';
	return 0;
}