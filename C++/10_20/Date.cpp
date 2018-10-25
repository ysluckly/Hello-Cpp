#include "Date.h"

//获取当月天数
int Date::GetMonthDay(int year, int month)
{
	//方法一：十二个if、else语句
	//方法二：switch分支语句
	//此处方法三：
	 static const int days[13] = {0, 31,28, 31,30, 31,30, 31,31,30, 31,30, 31 };//润年二月多一天
	 //4年一润百年不润400年一润且此处至于二月有关
	 if ((month == 2)&&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	 {
		 return 29;

	 }
	 return days[month];
}

//日期类关系操作符重载
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d. _month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}
 
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

// d1 >= d2
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}


//日期类操作符重载
// d1 + 100	  
//当+days大于该月总天数时，用days减去该月天数，月份month+1，差值即为新月份的天数。
//若遇到年末，即month = 12时，年份year++，月份month置1，否则month++）
Date Date::operator+(int day)
{
	Date ret(*this);

	if (day<0)
		return ret - abs(day);
	ret._day += day;

	while (ret._day > GetMonthDay(ret._year, ret._month))
	{
		ret._day -= GetMonthDay(ret._year,ret._month);
		if (12 == ret._month)
		{
			ret._year++;
			_month = 1;

		}
		else
		{
			_month += 1;
		}
	}
	return ret;
}

Date& Date::operator+=(int day)
{
	if (day<0)
	{
		return *this - abs(day);
	}
	
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		if (12 == _month)
		{
			_year++;
			_month = 1;

		}
		else
		{
			_month += 1;
		}
	}
	return *this;
}
//（与+days类似，用该月天数-days，
//其差值若小于0，且在年初，则年份year--，置月份month=12，否则month--）
Date Date::operator-(int day)
{
	Date ret(*this);

	if (day < 0)
		return ret + abs(day);
	ret._day -= day;
	while (ret._day <= 0)
	{

		if (ret._month == 1)
		{
			ret._year--;
			ret._month = 12;
		}
		else
		{
			ret._month--;
		}
		ret._day += GetMonthDay(ret._year,ret._month);

	}
	return ret;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
		return *this + abs(day);
	_day -= day;
	while (_day <= 0)
	{
		if (_month == 1)
		{
			_year--;
			_month = 12;
		}
		else
		{
			_month--;
		}
		_day += GetMonthDay(_year,_month);

	}
	return *this;
}
//（这里可以运用一个巧妙的方法，将当前对象拷贝构造为Max，引用对象拷贝构造为Min，
//如果Max<Min，调用库函数交换，并用一个状态量flag标记。再利用while循环，
//只要Max与Min不相等，Max--，计数器days++，days即为最终的相隔天数）
int Date::operator-(const Date& d)
{
	int flag = 1;
	Date Max(*this);
	Date Min(d);
	if ((*this) < d)
	{
		std::swap(Max, Min);
		flag = -1;
	}
	int days = 0;
	while (Max != Min)
	{
		--Max;
		++days;
	}
	return days*flag;
}
//（ + 1操作应该考虑天数为月末，月份为年末时的特殊情况，
//通过判断月末与年末，对指定的月份 + 1或年份 + 1，并置新月份 = 1）
Date& Date::operator++()// ++d => d.operator++(&d)
{
	_day++;
	if (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;

}
//（后置++与前置++类似，返回值略有差异，
//可以拷贝构造一个临时的函数来保存this指针保存的内容，最终返回临时的函数）
Date Date::operator++(int)// d++ => d.operator(&d, 0)
{
	Date ret(*this);
	_day++;
	if (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return ret;

}
// （-1操作应该考虑天数为月初，月份为年初时的特殊情况，
//通过判断月末与年末，对指定的月份-1或年份-1，并置新月份=12）
Date& Date::operator--() // --d 
{
	_day--;
	if (_day <= 0)
	{
		if (_month == 1)
		{
			_year--;
			_month = 12;
		}
		else
		{
			_month--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
//（与前置--类似，可以使用拷贝构造函数构造一个临时的函数，最终返回临时函数即可）
Date Date::operator--(int) // d--
{
	Date ret(*this);
	if (_day <= 0)
	{
		if (_month == 1)
		{
			_year--;
			_month = 12;
		}
		else
		{
			_month--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return ret;
}
// 重载输出 <<
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}
//重载输入>>
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}