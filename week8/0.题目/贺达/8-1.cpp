#include<bits/stdc++.h>
using namespace std;

struct act
{
    int s,e;
};

bool cmp(act a1,act a2)
{
    return (a1.e<a2.e);//比较结束时间
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       vector<act>a(n);
       for(int i=0;i<n;i++)
       {
           cin>>a[i].s>>a[i].e;
       }
       sort(a.begin(),a.end(),cmp);//排序找出结束时间最早的活动

       int cnt=1;
       int loca=a[0].e;
       for(int i=1;i<n;i++)
       {
           if(a[i].s>=loca)//符合条件便参加活动，并把此活动的结束时间赋给loca
           {
               cnt++;
               loca=a[i].e;
           }
       }
       cout<<n-cnt<<endl;

   }
   return 0;
}
