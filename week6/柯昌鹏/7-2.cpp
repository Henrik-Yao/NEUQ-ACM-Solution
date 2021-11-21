#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map< string ,string >pass;
map< string ,long long >id_hash;

int trs36(char i)
{//因为题中只有大小写字母和数字，考虑大小写字母和数字就ok
    if(i<='9') return i-'0';
    else if(i>='A'&& i<='Z') return 10+i-'A';
    else return 10+i-'a';
}
int trs(string a)
{   
    int sl=a.length();
    int l[5],left=sl%4,temp=4,i=0;
    while(temp--)//将字符串拆分成四个部分
    {   
        i++;
        if(left>0) l[i]=sl/4+1;
        else l[i]=sl/4;
        left--;
    }
    int re=0;
    i=0,sl=0;
    for(int j=1;j<=4;j++)
    {
        sl=sl+l[j];
        int sum=0;
        while(i<sl)//分别求每一段的和
        {
            sum=sum+trs36(a[i]);
            i++;
        }
        sum=sum%36;//计算出它的个位
        re=re*100+sum;//因为是36进制，没一个数字占十进制的两位
    }
    return re;//最后的hash值
}
int main ()
{
   string id,password;
   int t;
   cin>>t;
   char jud;
   while(t--)
   {
       cin>>jud>>id>>password;
       if(jud=='R')
       {
           if(id_hash[id]) cout<<"Repeated!"<<endl;//如果id对应的密码存在，返回真值
           else{
               pass[id]=password;//记录id和密码
               id_hash[id]=trs(password);//为后面的碰撞埋下伏笔
               cout<<"Signed!"<<endl;
           }
       }
       else {
           int hash=trs(password);//对于新的密码，计算hash值
           if(id_hash[id]==hash&& pass[id]==password) cout<<"Success!"<<endl;
           else if(id_hash[id]==hash) cout<<"Attention!"<<endl;
           else cout<<"Failed!"<<endl;
           }
   }
   return 0;
     
}