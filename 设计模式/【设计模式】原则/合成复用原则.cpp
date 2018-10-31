#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h> 
using namespace std;

class Cat
{
public:
	void sleep()
	{
		cout << "睡觉"<< endl;
	}
};

//创建一个新的猫，且增加一个功能，即能睡觉又能吃东西
//如果Cat有很多父类，cat的父类与AddCat高耦合，复杂度高
//通过继承完成
class AddCat:public Cat
{
public:
	void eat()
	{
		cout << "吃饭"<< endl;
		sleep();
	}
};

//使用组合方式添加吃东西
//使用组合降低Add2Cat与Cat耦合，跟Cat父类没有任何关系，
//只跟Cat与slepp有关系
class Add2Cat
{
public:
	Add2Cat(Cat* cat)
	{
		this->cat = cat;
	}
	void eat(Cat* cat)
	{
		cout <<"吃饭" << endl;
		cat->sleep();
	}
private:
	Cat* cat;
};
int main()
{
	Cat c;
	c.sleep();

	AddCat ac;
	ac.eat();

	Add2Cat ac(&c);
	ac.eat();

	system("pause");
	return 0;
}

