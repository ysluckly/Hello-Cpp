#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
/*
class bank
{
public:
	void save()
	{
		cout << "存款"<<endl;
	}
	void pay()
	{
		cout << "支付"<<endl;
	}
	void transfer()
	{
		cout << "转账"<<endl;
	}

	//添加一个行业务
	void jijin()
	{
		cout << "基金"<< endl;
	}	 写完不能写加入，违反单一原则，如果新加入工能有问题，系统就崩了
};	 */

//抽象 业务员类
class abstractbank
{
public:
	virtual void work() = 0; //抽象类接口

};
//存款
class save :public abstractbank
{
public:
	virtual void work()
	{
		cout << "存款"<< endl;
	}

};
//支付
class pay :public abstractbank
{
public:
	virtual void work()
	{
		cout <<"支付" << endl;
	}

};
//转账
class transfer :public abstractbank
{
public:
	virtual void work()
	{
		cout << "转账"<< endl;
	}

};

//添加基金
class add : public abstractbank
{
public:
	virtual void work()
	{
		cout << "基金" << endl;
	}
	
};
int main()
{
	abstractbank *sb = new save;
	sb->work();

	sb->work();
	delete sb;


	system("pause");
	return 0;
}
//改进后，新加功能不会影响原有功能
