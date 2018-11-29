#include "common.h"


template<class T,class Container = deque<T>>
class Queue
{
public:
	Queue()
	{
		;
	}
	void Pop()
	{
		_q.pop_front();
	}
	void Push(const T& x)
	{
		_q.push_back(x);
	}
	size_t  Size() const
	{
		return _q.size();
	}
	T& Back()
	{
		return _q.back();
	}
	const T& Back() const
	{
		return _q.back();
	}
	T& Front()
	{
		return _q.front();
	}
	const T& Front() const
	{
		return _q.front();
	}
	bool Empty()
	{
		return _q.empty();
	}

private:
	Container _q;

};