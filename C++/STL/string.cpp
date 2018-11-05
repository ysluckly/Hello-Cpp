#include "STL.h"

//////////////////////////////////容器
/////////////////////////////string
void test1()
{
	//string转char*
	string s = "abc";
	const char* str = s.c_str();
	//char*转string
	char* str2 = "casc";
	string s2(str2);

}
//string 初始化
void test2()
{
	string s;//默认构造
	string s1 = "cscsd";
	string s2(s1);
	string s4(10, 'o');

	cout << s << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s4 << endl;

}

//string赋值存取
void test3()
{
	//赋值
	string s;
	s = "abcd";

	string s2;
	s2.assign("pppp");

	//存取
	string s3 = "csdcsd";
	//越界挂掉
	for (int i = 0; i < s3.size(); ++i)
	{
		cout << s3[i] << " ";
	}
	cout << endl;

	//越界抛异常
	for (int i = 0; i < s3.size(); ++i)
	{
		cout << s3.at(i) << " ";
	}
	cout << endl;


	//异常案例
	try
	{
		//cout << s3[300] << endl;  //崩溃
		cout << s3.at(200) << endl;	//正常执行，抛异常
	}
	catch (...)
	{
		cout << "访问越界" << endl;

	}

}

//string拼接
void test4()
{
	string s = "aaa";
	string s2 = "bbbb";
	string s3 = s + s2;
	cout << s3 << endl;

	s += s2;
	cout << s << endl;

	//c成员方法 append
	s.append(s2);
	cout << s;
}

//string 查找 替换 
void test5()
{
	string s = "cdscca";
	//查找
	string yy = "cd";
	int pos = s.find(yy);

	char* pp = "cadssd";
	int pos1 = s.find(pp);

	int pos4 = s.rfind(yy);	 //倒序查找
	cout << pos << " " << pos1 << pos4 << endl;

	string s5 = "pppppp";
	//替换
	s.replace(0, 2, s5);
	cout << s;

}

//比较  子串 插入删除
void test6()
{
	//比较
	string s1 = "casc";
	string s2 = "svdvsd";
	int ret = s1.compare(s2);
	if (ret == 1)
	{
		cout << "s1>s2";
	}
	else if (ret == -1)
	{
		cout << "s1<s2";
	}
	else
	{
		cout << "xiangdeng";
	}

	//子串
	string s3 = "csdcnskns";
	string  s4 = s3.substr(0, 2);
	cout << s4.size();
	cout << endl << s4 << endl;
	//插入删除
	s3.insert(0, "dsd");
	cout << s3 << endl;

	s3.insert(s3.size() - 1, s3);
	cout << s3 << endl;

	s3.erase(0, 4);//前闭后开
	cout << s3 << endl;

}
//string 案例	
//检查邮箱是否存在（先检查是否合法）
void test7()
{
	string email = "acaccd56@email.com";

	int pos = email.find('@');
	int pos1 = email.find('.');

	if (pos == -1 || pos1 == -1)
	{
		cout << "不合法" << endl;
		system("pause");
		return;
	}
	if (pos > pos1)
	{
		cout << "不合法" << endl;
		system("pause");
		return;

	}

	//判断usrname
	string usrname = email.substr(0, pos);
	string::iterator pStart = usrname.begin();
	string::iterator pEnd = usrname.end();

	while (pStart != pEnd)
	{
		if (*pStart<97 && *pStart >122)
		{
			cout << "不合法" << endl;
			system("pause");
			return;
		}
		cout << *pStart << " ";
		pStart++;
	}
	cout << endl;

	//判断存在
	string remail = "zhaosi@itcast.cn";
	int ret = email.compare(remail);
	if (ret != 0)
	{
		cout << "不存在" << endl;

	}
	else
	{
		cout << "合法" << endl;
	}
}