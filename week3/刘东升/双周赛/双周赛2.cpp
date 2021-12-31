#include<bits/stdc++.h>
using namespace std;
void move(int n,string a,string b,string c);//定义一个简化模型函数 
int main()
{
    int n;string a,b,c;cin>>n>>a>>b>>c;
    move(n,a,b,c);
    return 0;
}
void move(int n,string a,string b,string c)//简化模型为移动n-1个盘子和最后一个盘子的情形 ，n为盘子数量，a为初始位置，b为中间柱子，c为最终柱子 
{
	if(n==1){
		cout<<a<<"->"<<c<<endl; //移动最后的盘子 
	}
	else{
		move(n-1,a,c,b);//移动至中间 
		cout<<a<<"->"<<c<<endl; 
		move(n-1,b,a,c); //最后一步 
	}
} 
