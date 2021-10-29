#include <iostream>
#include <cstring>
using namespace std;
void TrueMerge(string str,int front,int end){
	for(int i=front;i<=end;i++){
		for(int j=front;j<end;j++){
			if(str[j]>str[j+1])swap(str[j],str[j+1]);
		}
	}
}
void Merge(string str,int front,int end){
	if(front>end) return;
	if(front==end) {cout << str << endl;}
	else{
		for(int i=front;i<=end;i++){//选择第一个数
			swap(str[front],str[i]);//同，选择第一个数
			Merge(str,front+1,end);	
			//swap(str[front],str[i]);
			TrueMerge(str,front,end);
		}
	}
}
int main(){
	string str;
	getline(cin,str);
	for(int i=0;i<str.size();i++){
		for(int j=0;j<str.size()-1;j++){
			if(str[j]>str[j+1])swap(str[j],str[j+1]);
		}
	}
	Merge(str,0,str.size()-1);
	return 0;
}
