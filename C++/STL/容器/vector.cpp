#include "STL.h"
////////////////////////////vector
//初始化
void test8()
{
	vector<int> v;	//默认
	vector<int> v2(10, 5);//带参数构造，10个5
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v3);//拷贝构造

	int arr[] = { 2, 4, 5, 6 };
	vector<int> v5(arr, arr + sizeof(arr) / sizeof(int));

	for (int i = 0; i < v5.size(); ++i)
	{
		cout << v5[i] << " ";
	}
	cout << endl;

}
//Demo(技巧)
void print(vector<int>& a)
{
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test9()
{
	vector<int> v;
	vector<int> v1;

	for (int i = 0; i < 5; ++i)
	{
		v.push_back(i);
	}

	for (int i = 6; i < 10; ++i)
	{
		v1.push_back(i);
	}
	print(v);
	print(v1);
	v.swap(v1);
	cout << " 交换后" << endl;
	print(v);
	print(v1);

	//swap小技巧
	vector<int> v3;
	v3.resize(100);

	v3.clear();	//清除元素
	v3.push_back(2);
	v3.push_back(2);


	cout << "容量" << v3.capacity() << endl;
	cout << "大小" << v3.size() << endl;  //有效元素

	//节约空间，及时处理不必要的内存
	//分解：vector<int> v2(v3);v2.swap(v3);但是v2生命周期长
	//匿名生命周期一行
	vector<int>(v3).swap(v3);

	cout << "容量" << v3.capacity() << endl;
	cout << "大小" << v3.size() << endl;  //有效元素

}
//赋值
void test10()
{
	vector<int> v;
	v.assign(5, 1);//5个1

	vector<int> v1;
	v1.assign(v.begin(), v.end());

	vector<int> v2;
	v2 = v1;
}
//大小
void test11()
{
	int arr[] = { 2, 45, 6, 7, 5 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	cout << "size" << v.size() << endl;
	cout << "容量 " << v.capacity() << endl;

	if (v.empty())
	{
		cout << "kong" << endl;
	}
	else
	{
		cout << "feikong" << endl;
	}

}
//存取
void test12()
{
	int arr[] = { 2, 45, 6, 7, 5 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	try
	{
		//cout << v[100]<< endl; //崩溃
		cout << v.at(300);	//异常
	}
	catch (...)//三点所有异常
	{
		cout << "越界" << endl;
	}

	cout << "first" << v.front() << endl;
	cout << "back" << v.back() << endl;

}
//插入 删除
void test13()
{
	int arr[] = { 2, 45, 6, 7, 5 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	v.insert(v.begin(), 100);
	v.push_back(89);
	cout << v.back() << endl;

	vector<int>::iterator pStart = v.begin();
	vector<int>::iterator pEnd = v.end();

	while (pStart != pEnd)
	{
		cout << *pStart << " ";
		pStart++;
	}
	cout << endl;

	v.pop_back();
	v.erase(v.begin());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	v.erase(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << v.size();
	cout << v.capacity();
	cout << endl;

}
//vector 增长原理
void test14()
{
	int count = 0;
	vector<int> v;
	int* p = NULL;
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			count++;
		}

	}
	cout << count << endl;;	//30
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
//reserve 预留空间
void test15()
{
	int count = 0;
	vector<int> v;
	//直到超过才申请，减少开辟，拷贝，释放的开销
	//大大提高效率
	v.reserve(100000);

	int* p = NULL;
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			count++;
		}

	}
	cout << count << endl;;	//1
	cout << v.size() << endl;
	cout << v.capacity() << endl;

}