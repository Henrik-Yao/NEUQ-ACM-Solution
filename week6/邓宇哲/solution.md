# 字符串模式匹配
点名道姓用KMP算法，姑且将这道题作为模板背下来吧，注释都有好好标哦。  
失配的处理办法都是 point2 = Next[point2]; 呢
~~~c++
#include <iostream>
using namespace std;
void get_Next(string target, int tl, int *Next) //求出Next数组
{                                               //Next数组是从 target[0到i-1]前子串 的前缀后缀最大值
    int point1 = 0, point2;
    Next[0] = point2 = -1;                                    //next数组首位默认为-1
    while (point1 < tl)                                       //边界条件
        if (point2 == -1 || target[point1] == target[point2]) //类似于KMP的匹配
            Next[++point1] = ++point2;
        else
            point2 = Next[point2]; //失配
}
int KMP(string origin, string target, int ol, int tl)
{
    int Next[tl], sum = 0;
    get_Next(target, tl, Next); //获得next数组
    int point1 = 0, point2 = 0; //从0位开始匹配
    while (point1 < ol)         //临界值
    {
        if (point2 == -1 || origin[point1] == target[point2]) //相应字符匹配成功，继续
            point1++, point2++;
        else
            point2 = Next[point2]; //失配
        if (point2 == tl)
            sum++, point2 = Next[point2]; //point2==tl时，全字符串匹配成功，sum+1，point2置为Next[point2]按失配处理并继续开始新一轮匹配
    }
    return sum; //返回
}
int main()
{
    string origin, target;
    cin >> origin >> target;//cin是真的好智能呢
    int ol = origin.length(), tl = target.length();
    cout << KMP(origin, target, ol, tl);
    return 0;
}
~~~
# 妈妈再也不用担心我被拖库了
看起来就像是在让我们设计一个用户管理程序  
就作为一次宝贵的开发经验吧。  
使用map、set进行数据管理，就可以进行快速索引、对比，map主要是储存username和对应的password。本题的另一个重点就是hash，考虑到hash的唯一性，用set保存正合适。
```c++
#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, string> user;
set<long> hashs;//用于保存密码hash的set
long hashy(string);//好骚的函数名，害羞呢
main()
{
    int n;
    cin >> n;
    char func;//func=function，功能
    string name, password;
    for (int i = 0; i < n; i++)
    {
        cin >> func >> name >> password;
        if (func == 'R')
        {
            if (user.find(name) != user.end())//如果返回的迭代器没有指向末端，则早已存在此用户名
            {
                cout << "Repeated!" << endl;
                continue;
            }
            else
            {
                user[name] = password;//看起来像直接赋值，但在键值对不存在的情况下就是创建了
                cout << "Signed!" << endl;
                hashs.insert(hashy(password));//在set中插入password的hash
                continue;
            }
        }
        if (func == 'L')
        {
            if (user.find(name) == user.end())//找不到呀
            {
                cout << "Failed!" << endl;
                continue;
            }
            if (user[name] == password)//找得到，而且密码对
            {
                cout << "Success!" << endl;
            }
            else//密码不对呀
            {
                if (hashs.count(hashy(password)))//看看hash过不过
                {
                    cout << "Attention!" << endl;
                    continue;
                }
                else//连hash也没过
                    cout << "Failed!" << endl;
            }
        }
    }
}
long hashy(string a) //先录入密码再进行调用，否则可能会修改密码的值
{

    int point = 0;//指向a
    int hashcache[4] = {0}, data[4];//hashcache用来保存各个 "部分内部相加的和"。data各个部分字符的数量，后面保存 "和的个位数"
    int l = a.length();
    long hashhash = 0;//初始化要返回的值
    for (int i = 0; i < l; i++)//转化为36进制数
    {
        if (a[i] <= 'Z' && a[i] >= 'A')
        {
            a[i] = a[i] - 'A' + 10;
        }
        if (a[i] <= 'z' && a[i] >= 'a')
        {
            a[i] = a[i] - 'a' + 10;
        }
        if (a[i] <= '9' && a[i] >= '0')
        {
            a[i] = a[i] - '0';
        }
    }
    int mod = l % 4, wide = l / 4;//求出各个部分字符的数量
    for (int i = 0; i < 4; i++)
    {
        if (mod != 0)
        {
            data[i] = wide + 1;
            mod--;
        }
        else
        {
            data[i] = wide;
        }
    }
    for (int i = 0; i < data[0]; i++)//求出 "部分内部相加的和"
    {
        hashcache[0] = hashcache[0] + a[point++];
    }
    data[0] = hashcache[0] % 36;//获得个位数
    for (int i = 0; i < data[1]; i++)
    {
        hashcache[1] = hashcache[1] + a[point++];
    }
    data[1] = hashcache[1] % 36;
    for (int i = 0; i < data[2]; i++)
    {
        hashcache[2] = hashcache[2] + a[point++];
    }
    data[2] = hashcache[2] % 36;
    for (int i = 0; i < data[3]; i++)
    {
        hashcache[3] = hashcache[3] + a[point++];
    }
    data[3] = hashcache[3] % 36;
    for (int i = 0; i < 4; i++)//转化为四位的36进制数
    {
        hashhash = hashhash * 36 + data[i];
    }
    return hashhash;//返回hash
}
```
# 字符串个数匹配
练习算法，这次不采用KMP，采用先进的Sunday算法（更多时候Sunday算法是KMP的5倍速率，除非遇到很糟糕的target）
```c++
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define MAX_CHAR 256
void GetNext(string &p, int &ot, int *Next, unsigned long long sizes);
bool Sunday(string &origin, int &ol, string &target, int &tl);
void GetNext(string &p, int &ot, int *Next, unsigned long long sizes) //标记各个字符所在的最大位置
{
	memset(Next, 0, sizes);
	for (int i = 1; i <= ot; i++) //标记
		Next[int(p[i - 1])] = i;
}
bool Sunday(string &origin, int &ol, string &target, int &tl)
{
	int Next[MAX_CHAR]; //声明Next数组，用于存放字符
	unsigned long long sizes = sizeof(Next);
	GetNext(target, tl, Next, sizes);

	int j; // origin 的下标
	int k; // target 的下标
	int i = 0;
	bool finde = 0;
	while (i <= ol - tl) //走到尾部退出循环
	{
		j = i;											   //origin的下标指向最新的位置
		k = 0;											   //target的下标重置，指向首位
		while (j < ol && k < tl && origin[j] == target[k]) //如果相同，且未越界，则进行下一个字符的比对
			j++, k++;

		if (k == tl) //如果比对成功，则有k= target的长度，可进行操作
		{
			finde = 1;
			break;
		}
		if (i + tl < ol)							   //如果在范围内，则重新将i定义为
			i += (tl - Next[int(origin[i + tl])] + 1); ////////****算法核心****////////
		/*  origin[i+tl]  指的是原字符串下一个字符，Next[]是储存该字符位移量的数组。
            如果target里有该字符，则进行指定长度的位移，没有则位移 (target的长度 +1)   */
		else
			break; //优化
	}
	return finde;
}
main()
{
	string a[256], origin, target;//a用来保存各个由字母组成的字符串
	getline(cin,origin);//必须得用getline
	cin >> target;
	int ol = origin.length(), tl = target.length();

	int point = 0, sum = 0;//point是指向a
	bool last = 0;
	
	for (int i = 0; i < ol; i++)
	{
		if ((origin[i] >= 'a' && origin[i] <= 'z') || (origin[i] >= 'A' && origin[i] <= 'Z'))//如果当前是字母
		{
			if (last == 1)//如果上一个字符是其他字符
			{
				point++;
			}
			if (origin[i] >= 'A' && origin[i] <= 'Z')//大写统一变为小写
			{
				a[point] += origin[i] + 'a' - 'A';
			}
			else
				a[point] += origin[i];
			last = 0;//标记该字符是字母
		}
		else
		{
			last = 1;//标记该字符是其他字符
		}
	}
	for (int i = 0; i < target.size(); i++)//转化为小写
	{
		if (target[i] >= 'A' && target[i] <= 'Z')
		{
			target[i] += 'a' - 'A';
		}
	}
	for (int i = 0; i <= point; i++)//对a中的各个字符串进行查找
	{
		if (a[i].length() < target.length())//这肯定不是
		{
			continue;
		}
		else
		{
			int j = a[i].length();
			if(Sunday(a[i],j,target,tl))
			{
				sum++;
			}
		}
	}
	cout << sum;
}
```