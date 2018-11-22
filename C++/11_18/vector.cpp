#define _CRT_SECURE_NO_WARNINGS 1
# include "vector.h"

//capacity变化
void test1()	
{
	vector<int> foo;
	int size = foo.size();
	for (int i = 0; i < 1000; ++i)
	{
		foo.push_back(i);
		if (size != foo.capacity())
		{
			size = foo.capacity();
			cout << "The size is variers :" << size << endl;

		}
		
	}

}
//find/insert/erase
void test2()
{
	int a[] = { 1, 2, 4, 6, 9,2, 70 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	//find 查找3 所在迭代器的位置
	vector<int>::iterator pos = find(v.begin(),v.end(),4);

	//在pos位置插入333
	v.insert(pos, 333);
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	pos = find(v.begin(), v.end(),4);
	//删除pos的位置
	v.erase(pos);
	auto cit = v.begin();
	while (cit != v.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}
//operator[]+index支持的遍历，c++11新特性支持的遍历方式
void test3()
{
	int a[] = { 1, 2, 4, 6, 9, 2, 70 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	v[0] = 99;
	cout << v[0] << endl;

	//遍历方法一
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	//遍历方法二
	//auto it = v.begin();
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;

	//遍历方法三
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}
//迭代器失效问题 
//insert/erase导致迭代器失效
void test4()
{
	int a[] = { 1, 2, 4, 6, 9, 99, 70 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	//迭代器相当于指针，指向当前位置
	vector<int>::iterator pos = find(v.begin(), v.end(), 99);
	v.erase(pos);
	//此处会导致非法访问
	cout << *pos << endl;

	//在pos位置插入，导致迭代器失效，
	//insert失效，是因为插入数据可能会导致增容，
	//增容后pos还指向原来的空间，二原来的空间已经释放了 ，
	pos = find(v.begin(), v.end(), 99);
	v.insert(pos, 30);
	//导致非法访问
	cout << *pos << endl;
	
}

//常见迭代器失效场景，及改正方法
void test5()
{
	int a[] = { 1, 2, 4, 6, 9, 2, 70 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	//实现删除所有偶数
	//下面程序会崩溃掉，如果是偶数，erase会导致it失效
	//对失效的it自增，会导致程序崩溃
	vector<int>::iterator it = v.begin();
	while (it != v.begin())
	{
		if (*it % 2 == 0)//此方法不好，应改进 （*it&0x1）
		{
			v.erase(it);
		}
		++it;  //准确说是越界造成的程序崩溃
		//对于迭代器失效，g++可能是结果不正确或者报错，vs造成程序崩潰

	}

	//上面方法应该改进为
	vector<int>::iterator it = v.begin();
	while (it != v.begin())
	{
		if (*it % 2 == 0)//此方法不好，应改进 （*it&0x1）
		{
			it = v.erase(it);
		}
		else
		{
			++it;

		}
	}

}
int main()
{
	 
	//test1();
	//test2();
	//test3();
	test4();
	system("pause");
	return 0;
}

