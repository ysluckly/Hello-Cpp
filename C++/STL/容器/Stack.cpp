#include "STL.h"

//////////////////////////////// stack
void test21()
{
	stack<int> a;
	a.push(5);
	a.push(33);
	a.push(544);
	a.push(55);
	a.push(51);
	while (!a.empty())
	{
		int val = a.top();
		a.pop();
		cout << val<<" ";

	}
	cout << endl;

}
void test22()
{
	stack<int> a;
	a.push(5);
	a.push(33);
	a.push(544);
	a.push(55);
	a.push(51);

	stack<int> b(a);
	cout << b.size() << endl;


	while (!b.empty())
	{
		int val = b.top();
		b.pop();
		cout << val << " ";

	}
	cout << endl;
	cout << b.size()<<endl;
}
//¶ÔÏó
class teacher
{
public:
	teacher(string name,int age)
		:name(name)
		,age(age)
	{}
	string name;
	int age;
};
void test23()
{
	stack<teacher> a;
	teacher a1("aaa", 3);
	teacher a2("bbb", 45);
	teacher a3("ccc", 33);
	a.push(a1);
	a.push(a2);
	a.push(a3);

	while (!a.empty())
	{
		teacher val = a.top();
		a.pop();
		cout << val.name << " " << val.age << endl;;

	}
	cout << endl;
	cout << a.size() << endl;

}
//Ö¸Õë
void test24()
{
	stack<teacher*> a;
	teacher a1("aaa", 3);
	teacher a2("bbb", 45);
	teacher a3("ccc", 33);
	a.push(&a1);
	a.push(&a2);
	a.push(&a3);

	while (!a.empty())
	{
		teacher* val = a.top();
		a.pop();
		//cout << (*val).name << " " << (*val).age << endl;;
		cout << val->name << " " << val->age << endl;;

	}
	cout << endl;
	cout << a.size() << endl;
}

