#include "STL.h"

///////////////////////list
//初始化
void test28()
{
	list<int> l;
	list<int> l1(6,6);
	list<int> l2(l1);
	list<int> l3(l2.begin(),l2.end());
}
//插入删除
void print(list<int>& mylist)
{
	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;


}
void test29()
{
	//插入
	list<int> mylist;
	mylist.push_back(10);
	mylist.push_back(6);
	mylist.push_back(9);
	mylist.push_front(1);
	mylist.push_front(44);
	mylist.insert(mylist.begin(),666);
	mylist.insert(mylist.end(),3,99);
	print(mylist);

	mylist.remove(99);
	print(mylist);


	//删除
	mylist.pop_back();
	mylist.pop_front();
	print(mylist);

	mylist.erase(mylist.begin());
	mylist.erase(mylist.begin(),mylist.end());//mylist.clear();
	print(mylist);
	cout << mylist.size();

}
//大小 赋值
void test30()
{
	list<int> mylist;
	cout << mylist.size();

	for (int i = 0; i < 10; ++i)
	{
		mylist.push_back(i);
	}

	cout << mylist.size();
	if (mylist.empty())
	{
		cout << "kong";
	}
	else
	{
		cout << "bukong"<< endl;
	}
	list<int> mylist2;
	mylist2.assign(mylist.begin(),mylist.end());
	print(mylist2);

	mylist2.assign(3,66);
	print(mylist2);

	list<int> l3;
	l3 = mylist2;
	print(l3);

	mylist.swap(l3);
	print(mylist);
	print(l3);

	//反转
	l3.reverse();
	print(l3);

}
//sort	 默认小到大
bool compare(int v1, int v2)
{
	return v1 > v2;
}
void test31()
{
	list<int> mylist;
	cout << mylist.size();

	mylist.push_back(9);
	mylist.push_back(3);
	mylist.push_back(6);
	mylist.push_back(88);
	print(mylist);

	//小->大
	mylist.sort();
	print(mylist);

	//大->小
	mylist.sort(compare);
	print(mylist);

}


//类排序
bool comp(teacher t1, teacher t2)
{
	return t1.age > t2.age;
}
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

void test32()
{
	list<teacher> list1;
	teacher t1("aaa", 10);
	teacher t2("bbb", 4);
	teacher t3("ccc", 44);

	list1.push_back(t1);
	list1.push_back(t2);
	list1.push_back(t3);

	for (list<teacher>::iterator it = list1.begin(); it != list1.end(); ++it)
	{
		cout << it->age << " " << it->name <<" " << endl;
	}
	cout << endl;

	//大->小
	list1.sort(comp);
	
	for (list<teacher>::iterator it = list1.begin(); it != list1.end(); ++it)
	{
		cout << it->age << " " << it->name << " " << endl;
	}
	cout << endl;

}

