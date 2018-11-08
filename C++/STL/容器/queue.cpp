#include "STL.h"

////////////////////////////queue
void test25()
{
	queue<int> q;
	q.push(5);
	q.push(0);
	q.push(22);

	while (!q.empty())
	{
		cout << q.front()<<" ";
		q.pop();
	}
	cout << endl;
}
//¶ÔÏó
class teacher
{
public:
	teacher(string name, int age)
		:name(name)
		, age(age)
	{}
	string name;
	int age;
};
void test26()
{
	queue<teacher> a;
	teacher a1("aaa", 3);
	teacher a2("bbb", 45);
	teacher a3("ccc", 33);
	a.push(a1);
	a.push(a2);
	a.push(a3);

	while (!a.empty())
	{
		teacher val = a.front();
		a.pop();
		cout << val.name << " " << val.age << endl;;

	}
	cout << endl;
	cout << a.size() << endl;

}
//Ö¸Õë
void test27()
{
	queue<teacher*> a;
	teacher a1("aaa", 3);
	teacher a2("bbb", 45);
	teacher a3("ccc", 33);
	a.push(&a1);
	a.push(&a2);
	a.push(&a3);

	while (!a.empty())
	{
		teacher* val = a.front();
		a.pop();
		//cout << (*val).name << " " << (*val).age << endl;;
		cout << val->name << " " << val->age << endl;;

	}
	cout << endl;
	cout << a.size() << endl;
}

