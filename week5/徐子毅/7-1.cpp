#include <iostream>
#include <vector>
using namespace std;
struct people{
	int ID;
	char SEX;
	int F_ID;
	int M_ID;
}human[1000005];//保存一个人的信息
int ans;// 没用
int NUM;//不需要全局
vector<int>brotheryourfather;
vector<int>sisteryourfather;
void brothersearchyourfather(int n,int fullnum,int ans){
//	printf("BROTHER Searching at %d with ans is %d\n",n,ans);
	if(ans==5||n==-1||n<=0) return;
	else{
		if(human[n].F_ID!=-1) brotheryourfather.push_back(human[n].F_ID);
		if(human[n].M_ID!=-1) brotheryourfather.push_back(human[n].M_ID);
		brothersearchyourfather(human[n].F_ID,fullnum,ans+1);//递归查找父母
		brothersearchyourfather(human[n].M_ID,fullnum,ans+1);
	}
}
void sistersearchyourfather(int n,int fullnum,int ans){//和上面一样（凑行数（bushi
//	printf("SISTER Searching at %d with ans is %d\n",n,ans);
	if(ans==5||n==-1||n<=0) return;
	else{
		if(human[n].F_ID!=-1) sisteryourfather.push_back(human[n].F_ID);
		if(human[n].M_ID!=-1) sisteryourfather.push_back(human[n].M_ID);
		sistersearchyourfather(human[n].F_ID,fullnum,ans+1);
		sistersearchyourfather(human[n].M_ID,fullnum,ans+1);
	}
}
int main(){
	int NUM;
	cin >> NUM;
	int SelfID;
	for(int i=1;i<=1000000;i++){
		human[i].F_ID=-1;
		human[i].M_ID=-1;
		human[i].SEX='N';
	}
	for(int i=1;i<=NUM;i++){
		cin >> SelfID;
		human[SelfID].ID=SelfID;
		cin >> human[SelfID].SEX >> human[SelfID].F_ID >> human[SelfID].M_ID;
		if(human[SelfID].F_ID>=0){
			human[human[SelfID].F_ID].ID=human[SelfID].F_ID;
			human[human[SelfID].F_ID].SEX='M';
		}		
		if(human[SelfID].M_ID>=0){
			human[human[SelfID].M_ID].ID=human[SelfID].M_ID;
			human[human[SelfID].M_ID].SEX='F';
		}
	}
	
/*	for(int i=1;i<=NUM;i++){
		printf("ID = %d ; Sex = %c ; F_ID = %d ; M_ID = %d ;\n",human[i].ID,human[i].SEX,human[i].F_ID,human[i].M_ID);
	}*/
	int gan;
	cin >> gan;
	int brother,sister;
	for(int abc=1;abc<=gan;abc++){
		cin >> brother >> sister;
		if(human[brother].SEX==human[sister].SEX) {cout << "Never Mind" << endl;continue;}
		brotheryourfather.clear();
		sisteryourfather.clear();
		brothersearchyourfather(human[brother].ID,NUM,1);
		sistersearchyourfather(human[sister].ID,NUM,1);
/*		for(int i=0;i<brotheryourfather.size();i++) cout << brotheryourfather[i] << " ";
		cout << endl;
		for(int i=0;i<sisteryourfather.size();i++) cout << sisteryourfather[i] << " ";
		cout << endl;*/
		bool flag=true;
		for(int i=0;i<brotheryourfather.size();i++){//比较两个vector
			for(int j=0;j<sisteryourfather.size();j++){
				if(brotheryourfather[i]==sisteryourfather[j]&&brotheryourfather[i]!=0&&sisteryourfather[i]!=0){flag=false;break;}
			}
		}
		if(flag){cout << "Yes" << endl;continue;}
		else {cout << "No" << endl;continue;}
	}
	return 0;
}