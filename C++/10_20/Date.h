#pragma once

#include<iostream>
#include<Windows.h>
#include<cmath>
 
using namespace std;


//日期类实现操作符重载
class Date
{
public:
	 
	// 全缺省参数构造函数
	Date(int year = 1997, int month = 11, int day = 4)
		:_year(year)	//初始化列表
		, _month(month)
		, _day(day)
	{
		//检查合法
		if (year >= 0
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			cout <<"初始化ok！"<< endl;
		}
		else
		{
			cout << "Date Invalid" << endl;
			exit(EXIT_FAILURE);
		}
	}
	//析构函数
	~Date()
	{
		;
	}

	//拷贝构造函数：Date d3(d1)或者 Date d3 = d1
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值操作符重载
	Date&  operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//取地址操作符重载
	Date* operator&()
	{
		return this;
	}

	//关系操作符重载
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	//获取当月天数
	int GetMonthDay(int year, int month);

	//返回自身加引用，返回临时值返回
	Date operator+(int day);
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(const Date& d);
	Date& operator++();  
	Date operator++(int);  
	Date& operator--();  
	Date operator--(int);  

	//重载输出<<
	friend ostream& operator<<(ostream& _cout, const Date& d);

	//重载输入>>
	friend istream& operator>>(istream& _cin, Date& d);
	
private:
	int _year;
	int _month;
	int _day;
};

 