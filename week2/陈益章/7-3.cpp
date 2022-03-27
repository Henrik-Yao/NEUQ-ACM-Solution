#include<iostream>
#include<algorithm> 
using namespace std;
long long int pingpingshabi;
int dalunvzhuang=0;
int main()
{
	cin>>pingpingshabi;
	long long fangzhihehewoyiyangdeshabizhuangche[pingpingshabi];
		for (int haiyaoqubianliangminghaoleia=0;haiyaoqubianliangminghaoleia<pingpingshabi;haiyaoqubianliangminghaoleia++)
	cin>>fangzhihehewoyiyangdeshabizhuangche[haiyaoqubianliangminghaoleia];
	sort(fangzhihehewoyiyangdeshabizhuangche,fangzhihehewoyiyangdeshabizhuangche+pingpingshabi);
	for (int haiyaoqubianliangminghaoleia=0;haiyaoqubianliangminghaoleia<pingpingshabi;haiyaoqubianliangminghaoleia++)
	cout<<fangzhihehewoyiyangdeshabizhuangche[haiyaoqubianliangminghaoleia]<<" ";
	return dalunvzhuang;
}
