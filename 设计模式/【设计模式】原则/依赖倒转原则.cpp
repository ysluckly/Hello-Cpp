#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*class benchi
{
public:
	void run()
	{
		cout << "奔驰启动" << endl;
	}
};

class bm
{
public:
	void run()
	{
		cout << "宝马启动" << endl;
	}
};
class zhangsan
{
public:
	void drivebenchi(benchi* b)
	{
		b->run;
	}
	void drivebm(bm* b)
	{
		b->run;
	}
};*/	

//改进：如果人多了，车类型多，那么就会很乱，复杂，所以可以抽喜抽喜car，司机类
//抽像层
class Driver
{
public:
	virtual void drive(Car* car) = 0;
};

class Car
{
public:
	virtual void run() = 0;

};

//实现层

class zhangsan:public Driver
{
public:
	virtual void drive(Car* car)
	{
		cout << "zhangsan" << endl;
		car->run;
	}
};

class lisi:public Driver
{
public:
	virtual void drive(Car* car)
	{
		cout << "lisi" << endl;
		car->run;
	}

};
class benchi :public Car
{
public:
	virtual void run()
	{
		cout << "benchi" << endl;
	}

};
class bm :public Car
{
public:
	virtual void run()
	{
		cout << "bm" << endl;
	}

};
int main()
{
	/*//张三开奔驰
	benchi *b = new benchi;
	zhangsan *z = new zhangsan;
	z->drivebenchi(b);

	//张三开宝马
	bm *m= new bm;
	z->drivebm(m);
	 */

	//优点：运用的类少
	//逻辑层与实现层通过抽象层隔离叫做解耦合
	//zhangsan开奔驰
	Car	*b = new benchi;
	Driver *d = new zhangsan;
	d->drive(b);
	delete(b);
	delete(d);

	//lisi开宝马
	Car	*b = new bm;
	Driver *d = new lisi;
	delete(b);
	delete(d);

	d->drive(b);
	system("pause");
	return 0;
}
