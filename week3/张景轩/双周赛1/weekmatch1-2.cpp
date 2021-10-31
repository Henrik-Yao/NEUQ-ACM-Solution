#include<iostream>
using namespace std;

int n;


void hano(int n,string a,string b,string c)
{
  if(n==1)
  {
    cout<<a<<"->"<<c<<endl;
  }
  else
  {
      hano(n-1,a,c,b);
      cout<<a<<"->"<<c<<endl;
      hano(n-1,b,a,c);
  }
 
}

int main()
{
  cin>>n;
  string a,b,c;
  cin>>a>>b>>c;
  hano(n,a,b,c);
  return 0;
}

//递归，将第i个盘子放在c柱子，需要先将其上面的放到b盘，每层递归，实现全部移动