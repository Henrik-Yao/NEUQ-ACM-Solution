/*
7-5 ������
2018�����籭����������1:1ƽ��ǿ��İ���͢�Ӷ�һս������
�����߷��ֱ����˵����ֺ����ƺ����и����ɡ���son�������������ѿ������£�
���������õ���ά���˹��ϵĸ�ϵ���ƣ����ӵ��յ��ڸ��׵����Ӻ�׺������Ƕ��Ӿͼ� sson��
Ů����� sdottir����Ϊ�����˿ڽ��٣�Ϊ������׷��ܣ�
�����˽���ǰ���ø� App ��һ�������������ɴ�������ϵ�����������ʵ����� App �Ĺ��ܡ�
�����ʽ��
���������ڵ�һ�и���һ�������� N��1<N��10^5 ����Ϊ�����˿�������� N �У�ÿ�и���һ��������
��ʽΪ���� �գ����Ա��׺���������ַ������ɲ����� 20 ��Сд��Ӣ����ĸ��ɡ�
ά���˺����ǿ���ͨ���յĺ�׺�ж����Ա�ģ��������������յĺ���� m ��ʾ���ԡ�f ��ʾŮ�ԡ�
��Ŀ��֤������ÿ��ά���������Դ�˶������ԡ�
���һ�и��������� M��Ϊ��ѯ��������� M �У�ÿ�и���һ��������
��ʽΪ����1 ��1 ��2 ��2��ע�⣺��������ǲ�����׺�ġ�
�ĸ��ַ������ɲ����� 20 ��Сд��Ӣ����ĸ��ɡ�
��Ŀ��֤��������������ͬ���ġ�
�����ʽ��
��ÿһ����ѯ�����ݽ����һ������ʾ������Ϣ��
������Ϊ���ԣ�����������޹������ȣ������ Yes��
������Ϊ���ԣ���������ڣ���������������й������ȣ������ No��
������Ϊͬ�ԣ������ Whatever��
����һ�˲��������ڣ������ NA��
��ν����������޹������ȡ���ָ���˵Ĺ������ȣ�������ڵĻ���������κ�һ�������游���ָߡ�
����������
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
���������
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

