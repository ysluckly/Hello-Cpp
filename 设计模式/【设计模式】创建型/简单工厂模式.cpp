#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h> 
using namespace std;
/*
class fruit
{
public:
	fruit(string kind)
	{
		this->kind = kind;
		if (kind == "apple")
		{  //代表苹果
		}

		else if (this->kind == "banana")
		{
			//代表香蕉
		}
	}

	void GetName()
	{
		if (kind == "apple")
			cout << "我是苹果" << endl;

		else if (this->kind == "banana")
			cout << "我是香蕉" << endl;
	}

private:
	string kind;//水果种类
};
int main()
{
	//创建一个苹果
	fruit f("apple");
	f.GetName();

	//main函数跟fruit类的构造函数耦合度太高，随着水果种类的增加，构造函数越来越复杂
	system("pause");
	return 0;
}
不难看出，fruit类是一个巨大的类，在该类的设计中存在如下几个问题：
（1）在fruit类中包含有很多“if…else…”代码块，整个类中代码相当冗长，代码越长，阅读难度，维护难度，测试难度也越大，而且大量条件语句的存在还将影响系统的性能，程序在执行过程中需要做大量的条件判断
（2）fruit类的职责过重，它负责初始化和显示所有的水果对象，将各种水果对象的初始化和显示代码集中在一个类中实现，违反了“单一职责原则”，不利于类的重用和维护
（3）当需要增加新类型的水果时，必须修改fruit类的源代码，违反了“开闭原则”
*/
//定义一个水果抽象类，供具体水果使用和工厂使用
class fruit
{
public:
	virtual void GetName() = 0;

};

class Apple :public fruit
{
public:
	virtual void GeName()
	{
		cout << "我是苹果" << endl;
	}
};
class Banana :public fruit
{
public:
	virtual void GeName()
	{
		cout << "我是香蕉" << endl;
	}
};

//添加一个新品种
//只需要在创建一个类即可
class Pear :public fruit
{
public:
	virtual void GetName()
	{
		cout << "我是雅莉" << endl;

	}
};

//工厂
class factory
{
public:
	fruit* creat(string name)
	{
		if (name == "apple")
		{
			return new Apple;
		}
		else if (name == "banana")
		{
			return new Banana;
		}
		//当新增雅莉，factory就会不符合开闭原则
		else if (name == "pear")
			return new Pear;
	}
};
int main()
{
	factory* fac = new factory;
	fruit* fru = nullptr;
	/*
	我们用工厂创建一个具体的水果类，返回抽象类指针
	这就会发生多态
	那么此时抽象类指针指向了具体的子类，那么调用抽象方法
	就会调用子类的实现方法
	*/

	fru = fac->creat("apple");
	fru->GetName();
	delete fru;
	fru = nullptr;

	fru = fac->creat("banana");
	fru->GetName();
	delete fru;
	fru = nullptr;

	fru = fac->creat("pear");
	fru->GetName();
	delete fru;
	fru = nullptr;

	delete fac;
	return 0;
}