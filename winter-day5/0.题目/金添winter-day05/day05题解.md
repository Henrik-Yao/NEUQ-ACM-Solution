### day05 ���
* ������ܻؼ�������ȥ��
### 7-1 ��������
һ���ܼ򵥵�ˮ�塣
```C++
#include <bits/stdc++.h>
using namespace std;
int a[2000];
int num;
int sum=0;
void search(int n)
{
    for(int i=n+1;i<num;i++)
    {
        if(abs(a[i]-a[n])==1)
        {
            sum++;
        }
    }
    return;
}
int main()
{
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<num;i++)
    search(i);
    cout<<sum<<endl;

    return 0;
}
### 7-3 ������λ��
��ʽ��������
```C++
#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int num;
    cin>>num;
    for(int i=0;i<num*2;i++)
    cin>>a[i];
    sort(a,a+num*2);
    cout<<(a[num]+a[num-1])/2<<endl;

    return 0;
}
```
### 7-4 ���ֲ���
���ֲ��ҷ�Ϊ����ҿ��ͺ�����ұ��ͣ�����ע����Ⱥŵ��������������׳���
```C++
#include <bits/stdc++.h>
using namespace std;
int sum=0;
int search(int a[],int len,int tar)
{
    int left=0;
    int right=len-1;
    while(left<=right)   //����ҿ���
    {
        sum++;
        int mid=(left+right)/2;
        if(tar>a[mid])
        {
            left=mid+1;
        }
        else if(tar<a[mid])
        {
            right=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    int a[1000];
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    cin>>a[i];
    sort(a,a+num);
    int tar;
    cin>>tar;
    cout<<search(a,num,tar)<<endl;
    cout<<sum<<endl;
    return 0;
}
```
### 7-5 ������
������map�����ж�Ӧģ��
�����ò��鼯����
```C++
#include <bits/stdc++.h>
using namespace std;
int flag = 0;               //�ж�������û����ͬ������
map<string, string> people; //��������Ϊָ����ָ����˵�����Ϊ���
map<string, int> sex;       // 1Ϊ�У�2ΪŮ
map<string, int> visit;     //��¼����ѯ��ʱ�ҵ�������
void judge(string surname, string name)
{
    int len = surname.size();
    if (surname[len - 4] == 's' && surname[len - 3] == 's' && surname[len - 2] == 'o' && surname[len - 1] == 'n')
    {
        string father = surname.substr(0, len - 4);
        people[name] = father;
        sex[name] = 1;
    }
    else if (surname[len - 7] == 's' && surname[len - 6] == 'd' && surname[len - 5] == 'o' && surname[len - 4] == 't' && surname[len - 3] == 't' && surname[len - 2] == 'i' && surname[len - 1] == 'r')
    {
        string father = surname.substr(0, len - 7);
        people[name] = father;
        sex[name] = 0;
    }
    else
    {
        people[name] = name; //ʼ������
    }
}
void find(string name, int n) //���鼯
{
    if (n == 0)
    {
        // cout<<name<<endl;
        if (visit[name])
            flag = 1;
        else
            visit[name] = 1;
        return;
    }
    else
    {
        if (visit[name])
            flag = 1;
            visit[name]=1;
        find(people[name], n - 1);
    }
}
int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        string name;
        string surname; //������
        cin >> name >> surname;
        judge(surname, name);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string name1, surname1, name2, surname2;
        cin >> name1 >> surname1 >> name2 >> surname2;
        if (people[name1].empty() || people[name2].empty())
        {
            cout << "NA" << endl;
            continue;
        }
        if (sex[name1] == sex[name2])
        {
            cout << "Whatever" << endl;
            continue;
        }
        else
        {
            flag = 0;
            find(name1,3);
            find(name2,3);
            if(flag)
            cout<<"No"<<endl;
            else
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
```
### 7-7 ��ŭ��ţ
���õ����ֲ��Һ�̰�ģ�ʵ�����ö��ֲ���ȥ�Ѵ��Գ�����
```C++
#include <bits/stdc++.h>
using namespace std;
//̰��+����
//˼·�����ö��ְѼ������п��ܵĴ��г�����ͨ��̰���жϸ�ֵ�Ƿ��������⣬��ͨ������������
int cnt;//��ʱ���˶���ţ
int map1[100000]; //ũ���ͼ
int n,m;
bool judge(long long ans) //�ж�����ʹ𰸴�С��ϵ
{
    int cnt=0;
    cnt++;//��һͷţ����
    long long last=map1[0]; //����Ľڵ�
    for(int i=1;i<n;i++)
    {
        if(map1[i]-last>=ans)
        {
            cnt++; //�õ���ԣ���ţ����
            last=map1[i]; //����ڵ����
            if(cnt>=m)
            return true; //����ţ���ԴﵽҪ��ֵ��ans�����ٴ�һ��
        }
    }
    return false; //����ţ�ﲻ��Ҫ��ansӦ�ñ�Сһ�㡣
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>map1[i];
    }
    sort(map1,map1+n);
    long long left=0;
    long long right=map1[n-1]-map1[0];
    while(right>=left)
    {
        long long mid=(left+right)/2;
        if(judge(mid))
        {//ans�����ٴ�һ��
            left=mid+1;
        }
        else
        {//ansӦ��Сһ��
            right=mid-1;
        }
    }
    cout<<left-1;



    return 0;
}
```
