#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & (-x))
typedef long long var;
const int N = 1000010;
var read()
{
	var a = 0, s = 0, c = getchar();
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}
int firth,secth,lath;
int fir[N],sec[N],la[N];
int main() 
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int num;
   while(cin>>num)
   {
    if (num&1)//统计偶数 
       fir[++firth]=num;
    else//统计奇数 
       sec[++secth]=num;
    la[++lath]=num;//整体统计 
   }
  sort(fir+1,fir+1+firth);sort(sec+1,sec+1+secth);sort(la+1,la+1+lath);//整体排序 
   if (lath)
   {
    for (int i=1;i<lath;++i)//排序后直接输出排序好的总整体 
         cout<<la[i]<<"->";
    cout<<la[lath];//输出最后一个 
  }
  cout << "\n";
  if (firth) {
    for (int i=1;i<firth;++i)
      cout<<fir[i]<<"->";
    cout<<fir[firth];//跟总整体处理方式一样 
  }
  cout << "\n";
  if (sec) 
  {
    for (int i=1;i<secth;++i)
      cout<<sec[i]<<"->";
    cout<<sec[secth];
  }//同 
  return 0;
}
