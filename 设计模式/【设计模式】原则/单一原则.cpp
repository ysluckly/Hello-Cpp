#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h>
using namespace std;
/*如果多人修改hi出问题
class Cloths
{
public:
	void Shopping()
	{
		cout << "休闲服装" << endl;
	}
	void working()
	{
		cout << "正式服装" << endl;
	}
};
 */


//改进
class Clothwork
{
public:
	void style()
	{
		cout << "正式服装"<< endl;
	}
};
class Clothshopp
{
public:
	void style()
	{
		cout << "休闲服装" << endl;
	}
};
int main()
{
	/*Cloths c1;
	c1.Shopping();

	c1.working();
	*/
	Clothshopp c2;
	c2.style();

	Clothwork c3;
	c3.style();
	system("pause");
	return 0;
}
//修改一个方法，会影响到其他方法，违反单一职责原则，应该将其分离出来
