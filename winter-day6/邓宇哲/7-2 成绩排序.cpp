#include <iostream>
#include <algorithm>
using namespace std;
class Student
{
public:
	string name;
	int grade;
} list[25];
bool compare(Student, Student);
main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> list[i].name >> list[i].grade;
	}
	sort(list + 1, list + n + 1, compare);
	for (int i = 1; i <= n; i++)
	{
		cout << list[i].name << " " << list[i].grade << endl;
	}
}
bool compare(Student a, Student b)
{
	return (a.grade > b.grade || (a.grade == b.grade && a.name < b.name));
}