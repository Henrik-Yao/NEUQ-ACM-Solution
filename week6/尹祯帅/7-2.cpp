#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int n,i=0;
string mima[1001];
string str[1001],ymima[1001];
int main()
{
	char c;
	cin>>n;
	while(n--)
	{
		cin>>c;
		if(c=='R')  
		{
			bool ju=0;
			cin>>str[i++];
			cin>>ymima[i-1];
			for(int j=0;j<i-1;j++) 
			if(str[j]==str[i-1]) 
			{
				cout<<"Repeated!";
				if(n) cout<<'\n';
				str[i-1]="\0";
				ymima[i-1]="\0";
				i--;
				ju=1;
				break;
			}
			if(ju) continue;
			cout<<"Signed!";
			if(n) cout<<'\n';
			int yv=(ymima[i-1].size())%4,end=0,p=(ymima[i-1].size())/4;
			int begin,shu;
			for(int j=0;j<4;j++)
			{
				begin=end;
				end+=p;
				if(yv) end++,yv--;
				shu=0;
				for(   ;begin<end;begin++)
				{
					if(ymima[i-1][begin]>='0'&&ymima[i-1][begin]<='9') shu+=(int)(ymima[i-1][begin]-'0');
					else if(ymima[i-1][begin]>='a'&&ymima[i-1][begin]<='z') shu+=(int)(ymima[i-1][begin]-'a'+10);
					else  shu+=(int)(ymima[i-1][begin]-'A'+10);
				}
				shu%=36;
				if(shu<10) mima[i-1]+=(char)(shu+'0');
				else mima[i-1]+=(char)(shu-10+'a');
			}
		}
		else 
		{
			string yhm;
			cin>>yhm;
			bool jud=0;
			int q=-1;
			for(int j=0;j<i;j++) 
			if(str[j]==yhm) 
			{
				jud=1;
				q=j;
				break;
			}
			string yuanmm;
			cin>>yuanmm;
			if(!jud)
			{
				cout<<"Failed!";
				if(n) cout<<'\n';
				continue;
			}
			
			if(yuanmm==ymima[q]) 
			{
				cout<<"Success!";if(n) cout<<'\n';
				continue;
			}
			string mm="\0";
			int yv=(yuanmm.size())%4,end=0,shu,begin,o=(yuanmm.size())/4;
			for(int j=0;j<4;j++)
			{
				begin=end;
				end+=o;
				if(yv) end++,yv--;
				shu=0;
				for(  ;begin<end;begin++)
				{
					if(yuanmm[begin]>='0'&&yuanmm[begin]<='9') shu+=(int)(yuanmm[begin]-'0');
					else if(yuanmm[begin]>='a'&&yuanmm[begin]<='z') shu+=(int)(yuanmm[begin]-'a'+10);
					else  shu+=(int)(yuanmm[begin]-'A'+10);
				}
				shu%=36;
				if(shu<10) mm+=(char)(shu+'0');
				else mm+=(char)(shu-10+'a');
			}
			if(mm==mima[q]) cout<<"Attention!";
			else cout<<"Failed!";
			if(n) cout<<'\n';
		}
	}
	return 0;
}