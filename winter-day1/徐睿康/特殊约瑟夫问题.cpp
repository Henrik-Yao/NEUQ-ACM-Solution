#include<bits/stdc++.h>
using namespace std;
int n,m,k,pan[1010],flag,cnt=0;
int main()
{
	cin>>n>>m>>k;
	flag=1;
	while(1){
		for(int i=1;i<m;i++){
			while(1){
				flag--;
				if(flag<=0)flag+=n;
				if(pan[flag])continue;
				else break;
			}
		}
		cout<<flag<<' ';
		cnt++;
		if(cnt==n)break;
		pan[flag]=1;
		for(int i=1;i<k;i++){
			while(1){
				flag++;
				if(flag>n)flag-=n;
				if(pan[flag])continue;
				else break;
			}
		}
		cout<<flag<<' ';
		cnt++;
		if(cnt==n)break;
		pan[flag]=1;
	}
	return 0;
}
