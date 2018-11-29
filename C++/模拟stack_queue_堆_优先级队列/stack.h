#define _CRT_SECURE_NO_WARNINGS 1
#include "common.h"

template<class T,class Container = deque<T>>
class Stack
{
public:
	Stack()
	{
		;
	}

	void Push(const T& x)
	{
		 _s.push_back(x);
	}
	void Pop()
	{
		 _s.pop_back();
	}
	T& Top()
	{
		return _s.back();
	}
	const T& Top() const
	{
		return _s.back();
	}
	bool Empty()const 
	{
		return _s.empty();
	}
	int Size() const
	{
		return _s.size();
	}
	

private:
	Container _s;

};