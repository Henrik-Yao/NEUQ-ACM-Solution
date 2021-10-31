#include<iostream>
using namespace std;
int main()
{
 int t,m,n,temp,nl[200];
 cin>>t;
 for(int i=0;i<t;i++)
 {
  cin>>m;
  for(int j=0;j<m;j++)
  {
   cin>>nl[j];
  }
  cin>>n;
  for(int x=m;x<m+n;x++)   //直接从第m个数开始，接着原来的集合往里出入元素，至于为什么是n+m，可以用实际的例子来试试。
  {
   cin>>nl[x];
  }
 for(int b=0;b<m+n-1;b++)     //此处的m+n-1是因为，两个数进行比较的话就只比较了m+n-1次，也就是循环进行了n+m-1次。
  {
   for(int c=0;c<m+n-b-1;c++)    //这里进行的循环，首先进行外循环，然后在进行内循环，当内循环进行结束时，在回到外循环，让第一个数与第二个数进行比较，当第一个数比后者大时，吧第一个数赋予第二个数，进行类似的循环。
   {
    if(nl[c]>nl[c+1])
    {
     temp=nl[c];
     nl[c]=nl[c+1];
     nl[c+1]=temp;
    }
   }
  }
  for(int d=0;d<m+n;d++)
  {
   cout<<nl[d];               //这里的循环用来进行输出的
   if(d<m+n-1)              //这里进行的是，输出数字之间会有几个空格，通过if选择来控制
    cout<<' ';          //因为有n+m个数，所以只需有n+m-1个空格就行了
  }
  cout<<endl;
 }
}

