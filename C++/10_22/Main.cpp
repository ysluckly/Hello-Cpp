#include <iostream>

using namespace std;

namespace N1
{
	int a = 10;
	void TestFunc(int)
	{
		cout << "N1ddwdwdwde"<<endl;
	}
}

int a = 20;
void TestFunc(char)
{
	cout << "char " << endl;
}

class Test
{
public:
	void SetA(int a)
	{
		a = a;

	}
	void PrintA()
	{
		cout <<a << endl;
	}
	void TestFunc(double)		  
	{
		cout << "double" << endl;
	}
private:
	int a;
};
int main()
{
	Test t;
	t.SetA(30);
	cout <<N1::a<< endl;
	cout << a << endl;
	t.PrintA();

	return 0;
}