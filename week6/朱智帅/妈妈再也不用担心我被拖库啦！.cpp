#include<iostream>
#include<string>
#include<vector>
using namespace std;
int Haxitemp[1005], usernumber = 0;
struct userinfo
{
	string username, password;
	int HaXi;
};
userinfo USE[1005];
void Log_in(string username, string password)
{
	int i, j;
	for (i = 0; i < password.size(); i++)//将密码进行处理，使其变为全部小写。
		if (password[i] >= 'A' && password[i] <= 'Z')
			password[i] = password[i] - 'A' + 'a';
	//cout << password << endl;
	int passwordlen = password.size(), len[5];//对密码长度进行划分
	len[4] = passwordlen / 4;
	len[3] = (passwordlen - len[4]) / 3;
	len[2] = (passwordlen - len[3] - len[4]) / 2;
	len[1] = passwordlen - len[2] - len[3] - len[4];
	int Strat[6];//四个区域用来加和的起始位置记录。
	Strat[1] = 0, Strat[2] = len[1], Strat[3] = len[1] + len[2], Strat[4] = len[1] + len[2] + len[3], Strat[5] = len[1] + len[2] + len[3] + len[4];
	int sum[5] = { 0 }, Sum;//用来记录四个区域的密码和与总密码和为多少。
	for (i = 1; i < 5; i++)
	{
		for (j = Strat[i]; j < Strat[i + 1]; j++)
		{
			if (password[j] >= 'a' && password[j] <= 'z') sum[i] += password[j] - 'a' + 10;
			else sum[i] += password[j] - '1' + 1;
			//cout << password[j];//用于检测。
		}
		//cout << " ";
		//cout << sum[i] << " 对36取余后: ";//用于检验。
		sum[i] = sum[i] % 36;
		//cout << sum[i] << " ";//用于检验。
		//cout << endl;
	}
	Sum = ((sum[1] * 36 + sum[2]) * 36 + sum[3]) * 36 + sum[4];//按题目要求计算哈希值
	//cout << "哈希值: " << Sum << endl;
	bool tag = false;
	for (i = 0; i < usernumber; i++)
	{
		if (USE[i].username == username)
		{
			tag = true;
			if (USE[i].HaXi == Sum)
			{
				if (USE[i].password == password)
					cout << "Success!" << endl;
				else
					cout << "Attention!" << endl;
			}
			else
				cout << "Failed!" << endl;
		}
	}
	if (!tag) cout << "Failed!" << endl;
}
void Register(string username, string password)
{
	int i, j;
	for (i = 0; i < usernumber; i++)//如果重复则输出Repeate跳出函数。
	{
		if (USE[i].username == username)
		{
			cout << "Repeated!" << endl;
			return;
		}
	}
	for (i = 0; i < password.size(); i++)//将密码进行处理，使其变为全部小写。
		if (password[i] >= 'A' && password[i] <= 'Z')
			password[i] = password[i] - 'A' + 'a';
	//cout << password << endl;
	USE[usernumber].username = username;
	USE[usernumber].password = password;
	int passwordlen = password.size(), len[5];//对密码长度进行划分
	len[4] = passwordlen / 4;
	len[3] = (passwordlen - len[4]) / 3;
	len[2] = (passwordlen - len[3] - len[4]) / 2;
	len[1] = passwordlen - len[2] - len[3] - len[4];
	int Strat[6];//四个区域用来加和的起始位置记录。
	Strat[1] = 0, Strat[2] = len[1], Strat[3] = len[1] + len[2], Strat[4] = len[1] + len[2] + len[3], Strat[5] = len[1] + len[2] + len[3] + len[4];
	int sum[5] = { 0 }, Sum;//用来记录四个区域的密码和与总密码和为多少。
	for (i = 1; i < 5; i++)
	{
		for (j = Strat[i]; j < Strat[i + 1]; j++)
		{
			if (password[j] >= 'a' && password[j] <= 'z') sum[i] += password[j] - 'a' + 10;
			else sum[i] += password[j] - '1' + 1;
			//cout << password[j];//用于检测。
		}
		//cout << " ";
		//cout << sum[i] << " 对36取余后: ";//用于检验。
		sum[i] = sum[i] % 36;
		//cout << sum[i] << " ";//用于检验。
		//cout << endl;
	}
	Sum = ((sum[1] * 36 + sum[2]) * 36 + sum[3]) * 36 + sum[4];//按题目要求计算哈希值
	USE[usernumber++].HaXi = Sum;
	//cout << "哈希值: " << Sum << endl;
	cout << "Signed!" << endl;
}
int main()
{
	int n;
	char tag;
	string username, password;
	cin >> n;
	while (n--)
	{
		cin >> tag >> username >> password;
		if (tag == 'L')
			Log_in(username, password);
		else
			Register(username, password);
	}
	return 0;
}