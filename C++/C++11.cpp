#include <iostream>
using namespace std;

//int main()
//{
//	//// 相关类型的转换
//	//int i = 10;
//	//double d = static_cast<double>(i);
//
//	//// 不想关类型的转换
//	//int* p = &i;
//	//int j = reinterpret_cast<int>(p);
//
//	// 不想关类型的转换:去const属性
//	//volatile const int a = 2;
//	//int* p = const_cast<int*>(&a); // const int*/int const*
//	//*p = 3;
//	//cout << a << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	//virtual void f(){}
//
//	int _a;
//};
//
//class B : public A
//{
//public:
//	int _b;
//};
//
//void fun(A* pa)
//{
//	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
//	//B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pa);
//	//cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl;
//}
//
//int main()
//{
//	A a;
//	B b;
//	fun(&a);
//	fun(&b);
//	return 0;
//}

//#include <vector>
//#include <list>
//#include <map>
//
//// 初始化列表
//class Point
//{
//public:
//	Point(int x = 0, int y = 0)
//		: _x(x)
//		, _y(y)
//	{}
//private:
//	int _x;
//	int _y;
//};
//
//int main()
//{
//	//vector<int> v1 = {1, 2, 3};
//	//vector<int> v2{ 1, 2, 3 };
//	//list<int> l1{ 1, 2, 3 };
//	//map<int, int> m = { { 1, 1 }, { 2, 2 } };
//
//	Point p = {10, 10};
//	cout << typeid(p).name() << endl;
//
//	decltype(p) p1;
//
//	return 0;
//}
//
////template<class K, class V>
////class map
////{
////	map(initializer_list<pair<K, V>>& l))
////	{}
////};


//class A
//{
//public:
//	A()
//		:_a1(0)
//		, _a2(0)
//		, _a3(0)
//		, _a4(0)
//		, _a5(0)
//	{}
//
//	A(int a1)
//		:A()
//	{
//		_a1 = a1;
//	}
//
//private:
//	int _a1 ;
//	int _a2 ;
//	int _a3 ;
//	int _a4 ;
//	int _a5 ;
//};
//
//int main()
//{
//
//	return 0;
//}


//int main()
//{
//	// a是左值  10是右值
//	// 左边的一定是左值
//	// 右边的不一定是右值
//	int a = 10;
//	int b = a;
//
//	// 左值引用左值
//	int& lr1 = a;
//	// const左值引用引用右值  总结：左值引用的作用是什么？
//	const int& lr2 = 10;
//
//	// 右值引用右值
//	int&& rr1 = 10;
//
//	// 右值引用引用move(左值)
//	int&& rr2 = move(a);
//
//	return 0;
//}


class String
{
public:
	String(const char* str = "")
		:_str(new char[strlen(str)+1])
	{
		cout << "String(const char*)" << endl;
		strcpy(_str, str);
	}

	// s1(s2)
	// 拷贝构造
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;
		strcpy(_str, s._str);
	}

	// 移动构造
	String(String&& s)
		:_str(s._str)
	{
		cout << "String(String&& s)" << endl;
		s._str = nullptr;
	}

	String& operator=(const String& s)
	{
		cout << "String& operator=(const String& s)" << endl;
		if (this != &s)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}

		return *this;
	}

	//// 移动赋值
	//// s1 = die;
	//String& operator=(String&& s)
	//{
	//	cout << "String& operator=(String&& s)" << endl;
	//	swap(_str, s._str);
	//	return *this;
	//}

	~String()
	{
		delete[] _str;
	}

	const char* c_str()
	{
		return _str;
	}
private:
	char* _str;
};

String operator+(const String& s1, const String& s2)
{
	String ret(s1);
	//ret += s2;

	return ret;
}

String GetString(char* pStr)
{
	String ret(pStr);
	return ret;
}

#include <queue>


struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	String _data;

	ListNode(const String& x)
		:_data(x)
	{}

	ListNode(String&& x)
		:_data(forward<String>(x))
	{}
};

class List
{
public:
	void PushBack(const String& x)
	{
		ListNode* newnode = new ListNode(x);
		// ....
	}

	void PushBack(String&& x)
	{
		ListNode* newnode = new ListNode(forward<String>(x));
		// ....
	}
};

void Fun(int &x){ cout << "lvalue ref" << endl; }
void Fun(int &&x){ cout << "rvalue ref" << endl; }
void Fun(const int &x){ cout << "const lvalue ref" << endl; }
void Fun(const int &&x){ cout << "const rvalue ref" << endl; }

template<typename T>
void PerfectForward(T &&t){ Fun(std::forward<T>(t)); }

//int main()
//{
//	//String s = GetString("hello");
//	/*String s;
//	s = GetString("hello");*/
//
//	//String s("hello");
//	//queue<String> q;
//
//	//q.push(s);
//	//q.push(move(s));
//	//q.push("world");
//
//	//queue<pair<int, int>> prq;
//	//pair<int, int> pr(1, 1);
//	//prq.push(pr);
//	//prq.push(make_pair(2,2));
//	//prq.emplace(3, 3);
//
//
//	/*int a = 10;
//	int& lr1 = a;
//	const int& lr2 = 10;
//
//	int&& rr1 = 10;
//	int&& rr2 = move(a);*/
//
//	//String s = GetString("hello");
//
//	String s1("hello");
//	String s2("world");
//
//	List l;
//	l.PushBack(s1);
//	l.PushBack(move(s2));
//
//	return 0;
//}
//


struct Goods
{
	string _name;
	double _price;
	size_t _sales_volume;
};

struct PriceCompareLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct SalesVolumeCompareLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._sales_volume < gr._sales_volume;
	}
};

//int main()
//{
//	vector<Goods> goods = { { "苹果", 2.1, 1000 }, { "香蕉", 3, 100 }, { "橙子", 2.2, 500 }, { "菠萝", 1.5, 50} };
//	std::sort(goods.begin(), goods.end(), PriceCompareLess());
//	std::sort(goods.begin(), goods.end(), SalesVolumeCompareLess());
//
//	auto price_compare_less = [](const Goods& g1, const Goods& g2)->bool
//								{ 
//									return g1._price < g2._price;
//								};
//
//	cout << price_compare_less(goods[0], goods[1]) << endl;
//	std::sort(goods.begin(), goods.end(), price_compare_less);
//	std::sort(goods.begin(), goods.end(), [](const Goods& g1, const Goods& g2)->bool
//											{ 
//												return g1._price < g2._price;
//											});
//
//	std::sort(goods.begin(), goods.end(), [](const Goods& g1, const Goods& g2)->bool
//											{
//												return g1._sales_volume > g2._sales_volume;
//											});
//
//
//	return 0;
//}


//int main()
//{
//	int a = 0, b = 1;
//
//	auto swapab1 = [](int& a, int& b)
//				{
//					int c = a;
//					a = b;
//					b = c;
//				};
//
//	swapab1(a, b);
//
//	cout << a << endl;
//	cout << b << endl;
//
//	/*auto swapab2 = [a, b]()mutable
//	{
//		int c = a;
//		a = b;
//		b = c;
//	};
//
//	swapab2();
//
//	cout << a << endl;
//	cout << b << endl;*/
//
//	auto swapab2 = [&a, &b]
//	{
//		int c = a;
//		a = b;
//		b = c;
//	};
//
//	swapab2();
//
//	cout << a << endl;
//	cout << b << endl;
//
//	auto swapab3 = [&]
//	{
//		int c = a;
//		a = b;
//		b = c;
//	};
//
//	swapab3();
//
//	cout << a << endl;
//	cout << b << endl;
//
//
//	return 0;
//}

#include <thread>
#include <mutex>
#include <atomic>

int main()
{
	const size_t n = 1000000;
	size_t count = 0;
	mutex mtx;
	atomic<size_t> acount = 0;

	auto add_func = [&](size_t* begin, size_t* end)
	{
		*begin = clock();
		for (size_t i = 0; i < n; ++i)
		{
			/*mtx.lock();
			count++;
			mtx.unlock();*/
			acount++;
		}
		*end = clock();
	};

	size_t begin1 = 0, end1 = 0;
	std::thread t1(add_func, &begin1, &end1);

	size_t begin2 = 0, end2 = 0;
	std::thread t2(add_func, &begin2, &end2);

	t1.join();
	t2.join();

	cout << end1 - begin1 << endl;
	cout << end2 - begin2 << endl;

	cout << count << endl;

	return 0;
}
