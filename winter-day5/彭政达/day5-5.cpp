/*
7-5 冰岛人
2018年世界杯，冰岛队因1:1平了强大的阿根廷队而一战成名。
好事者发现冰岛人的名字后面似乎都有个“松”（son），于是有网友科普如下：
冰岛人沿用的是维京人古老的父系姓制，孩子的姓等于父亲的名加后缀，如果是儿子就加 sson，
女儿则加 sdottir。因为冰岛人口较少，为避免近亲繁衍，
本地人交往前先用个 App 查一下两人祖宗若干代有无联系。本题就请你实现这个 App 的功能。
输入格式：
输入首先在第一行给出一个正整数 N（1<N≤10^5 ），为当地人口数。随后 N 行，每行给出一个人名，
格式为：名 姓（带性别后缀），两个字符串均由不超过 20 个小写的英文字母组成。
维京人后裔是可以通过姓的后缀判断其性别的，其他人则是在姓的后面加 m 表示男性、f 表示女性。
题目保证给出的每个维京家族的起源人都是男性。
随后一行给出正整数 M，为查询数量。随后 M 行，每行给出一对人名，
格式为：名1 姓1 名2 姓2。注意：这里的姓是不带后缀的。
四个字符串均由不超过 20 个小写的英文字母组成。
题目保证不存在两个人是同名的。
输出格式：
对每一个查询，根据结果在一行内显示以下信息：
若两人为异性，且五代以内无公共祖先，则输出 Yes；
若两人为异性，但五代以内（不包括第五代）有公共祖先，则输出 No；
若两人为同性，则输出 Whatever；
若有一人不在名单内，则输出 NA。
所谓“五代以内无公共祖先”是指两人的公共祖先（如果存在的话）必须比任何一方的曾祖父辈分高。
输入样例：
15
chris smithm
adam smithm
bob adamsson
jack chrissson
bill chrissson
mike jacksson
steve billsson
tim mikesson
april mikesdottir
eric stevesson
tracy timsdottir
james ericsson
patrick jacksson
robin patricksson
will robinsson
6
tracy tim james eric
will robin tracy tim
april mike steve bill
bob adam eric steve
tracy tim tracy tim
x man april mikes
输出样例：
Yes
No
No
Whatever
Whatever
NA
*/
#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
int p[100010],cnt[100010],dx[100010],dy[100010],sex[100010]; 
string ming[100010], xing[100010];
bool judge(int x, int y){
	memset(cnt,0,sizeof(cnt));
	memset(dx,0,sizeof(dx));
	memset(dy,0,sizeof(dy)); 
    cnt[x]=1,cnt[y]=1;
    while(p[x]!=-1){ 
        cnt[p[x]]++;
        dx[p[x]]=dx[x] + 1;
        if(p[x]==y) return 0; 
        x=p[x];
    }
    while(p[y]!=-1){
        cnt[p[y]]++;
        dy[p[y]]=dy[y]+1;
        if(cnt[p[y]] > 1) 
            if(dy[p[y]]>=4 && dx[p[y]] >= 4) return 1;
            else return 0;
        y=p[y];
    }
    return 1;
}
int main(){
	int n,m;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>ming[i]>>xing[i];
		mp[ming[i]]=i; 
		int t=xing[i].size()-1;
		if(xing[i][t]=='m' || xing[i][t]=='n') sex[i]=1; 
		else sex[i]=-1;	
		string s="";
		if(xing[i][t]=='n')
			for(int j=0;j<t-3;j++) s+=xing[i][j];
		else if(xing[i][t]=='r')
			for(int j=0;j<t-6;j++) s+=xing[i][j];
		xing[i]=s;  
	}	
	memset(p,-1,sizeof(p));
	for(int i=1; i<=n; i++)
		if(mp[xing[i]]>0) p[i]=mp[xing[i]]; 
	cin>>m;
	string s1,s2,s3,s4;
	while(m--){
		cin>>s1>>s2>>s3>>s4;
		int x=mp[s1],y=mp[s3];  
		if(!sex[x]||!sex[y]) cout<<"NA"<<endl; 
		else if(sex[x]==sex[y]) cout<<"Whatever"<<endl; 
		else{ 
			if(judge(x,y)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;			
		}			
	} 
} 

