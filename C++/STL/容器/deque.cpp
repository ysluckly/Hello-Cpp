#include "STL.h"
////////////////////////////deque 
//初始化
void test16()
{
	deque<int> d;//默认构造
	deque<int> d1(5, 9); //5个9,带参构造

	deque<int> d2(d1.begin(), d1.end());
	deque<int> d3(d2);
}
//赋值，
void test17()
{
	deque<int> d1(10,5);

	deque<int> d;
	d.assign(10,5);
	d.assign(d1.begin(),d1.end());
	d = d1; 
}
//大小
void test18()
{
	deque<int> d1(10, 5);
	cout << d1.size() << endl;

	if (d1.empty())
	{
		cout << "KONG" << endl;
	}
	else
	{
		cout << "FEIKONG" << endl;
	}
	d1.resize(5);
	cout << d1.size() << endl;

	d1.resize(15);	 //初始化0
	cout << d1.size() << endl;


}
//插入 删除
void test19()
{
	deque<int> d1(10, 5);
	cout << d1.size() << endl;

	deque<int> d;
	d.insert(d.begin(),88);
	d.insert(d.end(), 88);
	d.insert(d.end(),5, 88);

	//d.insert(d.begin(),d1.begin(),d1.end);

	d.push_back(19);
	d.push_back(15);

	d.push_front(2);
	d.push_front(99);

	for (deque<int>::iterator it = d.begin(); it != d.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//尾删
	while (d.size() > 0)
	{
		cout << d.back()<<" ";
		d.pop_back();
	}
	cout << endl;

	cout << d.size() << endl;
	//头删
	while (!d.empty())
	{
		cout << d.front() << " ";
		d.pop_front();
	}
}
//deque 案例
//评委打分系统（sort排序）
//5 选手 10 评委
//去除最高分，最低分，取出平均分
//对选手成绩排序
class player
{
public:
	player(string name, int score)
		:_name(name)
		,_score(score)
	{}
	string _name;
	int _score;
};
//创建选手
void CreatPlayer(vector<player>& v)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; ++i)
	{
		string name = "选手";
		name += nameseed[i];
		player p(name, 0);
		v.push_back(p);
	}
}

//打分
bool mycompare(int p1, int p2)
{
	if (p1 < p2)  //小到大
	{
		return true;
	}
	else
	{
		return false;
	}
}
void  SetScore(vector<player>& v)
{
	for (vector<player>::iterator it = v.begin(); it != v.end(); ++it)
	{
		deque<int> dscore;
		for (int i = 0; i < 10; i++)
		{
			int score = 50 + rand() % 50;//打分
			dscore.push_back(score);

		}
		//排序
		sort(dscore.begin(), dscore.end(),mycompare);
		/*for (deque<int>::iterator it = dscore.begin(); it != v.end; ++it)
		{
			cout << *it << endl;
		}*/
		dscore.pop_front();
		dscore.pop_back();

		//分数总和
		int total = 0;
		for (deque<int>::iterator dit = dscore.begin(); dit!=dscore.end(); ++dit)
		{
			total += *dit;
			 
		}
		int avg = total / dscore.size();
		it->_score = avg;
	}
}
//显示
void ShowScore(vector<player>& p)
{
	for (vector<player>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout <<"姓名:"<< it->_name<<"   "<<"fenshu:"<<it->_score << endl;
	}
	cout << endl;
}
void test20()
{
	vector<player> play;
	CreatPlayer(play);
	SetScore(play);
	ShowScore(play);
}