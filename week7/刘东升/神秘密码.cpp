#include<bits/stdc++.h>
using namespace std;
string prints(string partten);
int main()
{
    string partten;cin>>partten;cout<<prints(partten);
}
string prints(string partten)
{
    int i=0;
    while(partten[i]!='\0')
    {
        if(partten[i]=='[')//进行判断是否需要进行处理 
        {
        	bool other=false;//这里面是不是还有别的[号
			int flo=1;//[号的个数，遇见]时-1 //
			int first=0;//另外[号的下标 
			int j=i;
            for(j=i+1; flo; j++)//先找到匹配的]号的位置 
            {
            	if(partten[j]=='[')
            	{
            		other=true;//存在另一个[ 
            		flo+=1;
            		if(first==0)
					{
						first=j;
					}
				}
				if(partten[j]==']')
				{
					flo-=1;//遇到了 
				}
			}
			int begin=i+2;	//从第二个开始找 
			int times=partten[i+1]-'0';
			if((partten[i+2]>='0')&&partten[i+2]<='9')
			{
				times*=10;
				times+=partten[i+2]-'0';
				begin=i+3;
			}
			if(other)//如果还有符号 
			{
				string re, h_re, tr;
				for(int k=begin; k<first; k++){
				h_re+=partten[k];
				}
				for(int k=first; k<j-1; k++){
				re+=partten[k];
				}
				re=prints(re);//再次重复上述流程 
				re=h_re+re;
				for(int i=0; i<times; i++){
				tr+=re;}
				string up_part, dw_part;
				for(int k=0; k<i; k++){
				up_part+=partten[k];}
				for(int k=j; partten[k]!='\0'; k++){
				dw_part+=partten[k];}
				partten=up_part+tr+dw_part;
			}
			else
			{
				string re, tr;
				for(int k=begin; k<j-1; k++)
				{
					re+=partten[k];
				}
				for(int i=0; i<times; i++)	tr+=re;
				string up_part, dw_part;
				for(int k=0; k<i; k++)	up_part+=partten[k];
				
				for(int k=j; partten[k]!='\0'; k++)	dw_part+=partten[k];
				partten=up_part+tr+dw_part;
			}
        }
        i+=1;
    }
    return partten;
}
