#include<bits/stdc++.h>
using namespace std;
struct pyd{
	string c[101];
	int number[101],l;
};
struct yhd{
    string a;
    int t,p;
};
yhd yhdui[10001];
pyd pydui[101];
string b[101],c[101],nextt[101][101];
int n,m,l[101],j,b1,q=0;
double ans=0;bool pp;
void f1(int beginn,int b1){
	cout<<pydui[b1].c[j]<<endl;
	b[q++]=pydui[b1].c[j];
	
	if(nextt[b1][j]!="")
	f1(j++,b1);
}
void f(int beginn,int b1){
	cout<<yhdui[beginn].a<<endl;
	b[q++]=yhdui[beginn].a;
	ans+=yhdui[beginn].p;
	if(nextt[b1][j]!="")
	f1(j++,b1);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>pydui[i].l;
		cin>>pydui[i].c[0];//第i个朋友列的首元素 
		for(int j=1;j<l[i];j++){
			cin>>pydui[i].c[j];
			nextt[i][j-1]=pydui[i].c[j];
		}
	}
	for(int i=0;i<n;i++)
	cin>>yhdui[i].a>>yhdui[i].t>>yhdui[i].p;
	sort(yhdui.t,yhdui.t+n);
	for(int i=0;i<n;i++){
		pp=1;
		for(int v=0;v<=q;v++)
		if(yhdui[i].a==b[v])pp=0;
		if(pp){
			for(int k=0;k<m;k++)
			if(b[k]==yhdui[i].a)	
			b1=k;
			j=0;
			f(i,b1);
		}
	}
	cout<<setprecision(1)<<ans/n<<endl;	
	return 0;
}
