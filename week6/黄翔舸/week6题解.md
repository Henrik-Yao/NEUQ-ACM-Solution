week6题解

1，

使用kmp算法，难点在next数组。next数组可以写成递推的形式，用一个总体的数学公式即为：

![img](https://img-blog.csdnimg.cn/2020021910504033.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NjAwNzI3Ng==,size_16,color_FFFFFF,t_70)

利用递归遍历next数组即可。

2.拖库

哈希值的选取可以1e9+7；且防止过大，应当每次都取模，注意取模是有时候会出现复数的情况，可以+k*mod来避免复数的出现；

将字符串分为四块方法：字符串长度为L,则至少每块有L/4个字符，L对4求余值为y，则前y个字串的长度为L/4+1。很明显y值只有0、1、2、3这四种取值可能。
对字串的哈希值求解方法：定义一个int变量sum，从左到右遍历字串，若str[i]为数字字符，则sum+=str[i]-‘0’(即转为int型加给sum);若str[i]为字母，(我这里将所有大写字母转为小写字母来进行计算)，sum+=str[i]-‘a’+10;也就是说，将字符类型值转为相应int类型值。算出和之后对36求余，余值小于10，即为对应的字符1-9；余值大于10，即为sum-10+'a’对应的小写字母。
对于注册和登录方法：使用map来存储已注册账号所对应的密码及密码的哈希值。即map<string,pair<string,string> > mp;

3.在第一题理解的基础上多加几个选择条件，将字母区分筛选即可。

if (s1[i] < 'a' || s1[i]>'z')

if (s2[i] >= 'A' && s2[i] <= 'Z')

if (s1[i] >= 'A' && s1[i] <= 'Z')

多进行几步筛选达到子串筛选的效果