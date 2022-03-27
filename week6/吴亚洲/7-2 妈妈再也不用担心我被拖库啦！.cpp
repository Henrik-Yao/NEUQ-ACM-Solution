#include<bits/stdc++.h>
using namespace std;
int n;
char hashchar(string aa)
{
	int len=aa.length();
	for(int i=0;i<len;i++)
	{
		if(aa[i]>='A'&&aa[i]<='Z')
		aa[i]+='a'-'A';
	}
	int sum=0;
	for(int i=0;i<len;i++)
	{
		if(aa[i]>='a'&&aa[i]<='z')
		sum+=(10+(int)(aa[i]-'a'));
		else
		sum+=(int)(aa[i]-'0');
	}
	sum%=36;
	if(sum<10)
	return (char)('0'+sum);
	else
	return (char)(sum-10+'a');
}
string Hash(string a)
{
	int len=a.length();
	int devide[5]={};
	for(int i=0;i<len%4;i++)
	devide[i]++;
	for(int i=0;i<4;i++)
	devide[i]+=len/4;
	string ans="0000";
	int j=0;
	for(int i=0;i<4;i++)
	{
		string aa=a.substr(j,devide[i]);
		ans[i]=hashchar(aa);
		j+=devide[i];
	}
	return ans;
}
struct Node
{
	string zh,mm,hash;
}node[10000];
int find(string zh,int n)
{
	for(int i=0;i<n;i++)
	if(node[i].zh==zh)
	return i;
	return -1;
}
int main()
{
	cin>>n;
	int num=0;
	char x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		string zh,mm;
		cin>>zh>>mm;
		if(x=='R')
		{
			if(find(zh,num)>=0)
			cout<<"Repeated!"<<endl;
			else
			{
				node[num].zh=zh;
				node[num].mm=mm;
				node[num].hash=Hash(node[num].mm);
				cout<<"Signed!"<<endl;
				num++;
			}
		}
		else
		{
			string MM=Hash(mm);
			if(find(zh,num)==-1)
			{
				cout<<"Failed!"<<endl;
				continue;
			}
			if(node[find(zh,num)].mm==mm)
			{
				cout<<"Success!"<<endl;
				continue;
			}
			if(node[find(zh,num)].hash==MM)
			{
				cout<<"Attention!"<<endl;
				continue;
			}
			else
			cout<<"Failed!"<<endl;
		}
	}
}
