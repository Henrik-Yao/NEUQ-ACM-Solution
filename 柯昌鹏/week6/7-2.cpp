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
        while(i<sl)
        {
            sum=sum+trs36(a[i]);
            i++;
        }
        sum=sum%36;
        re=re*100+sum;
    }
    return re;
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
           if(id_hash[id]) cout<<"Repeated!"<<endl;
           else{
               pass[id]=password;
               id_hash[id]=trs(password);
               cout<<"Signed!"<<endl;
           }
       }
       else {
           int hash=trs(password);
           if(id_hash[id]==hash&& pass[id]==password) cout<<"Success!"<<endl;
           else if(id_hash[id]==hash) cout<<"Attention!"<<endl;
           else cout<<"Failed!"<<endl;
           }
   }
   return 0;
     
}