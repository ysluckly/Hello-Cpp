#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
#include "queue.h"
#include "priority.h"
#include "heap.h"

void TestStack()
{
	//Stack<int,deque<int>> s;
	//Stack<int, vector<int>> s;
	//Stack<int,list<int>>  s;

	Stack<int> s;
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Push(6);

	cout << s.Top() << endl;
	cout << s.Size() << endl;

	s.Pop();

	cout << s.Top() << endl;
	cout << s.Size() << endl;
}



void TestQueue()
{
	Queue<int> q;

	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(400);

	cout << q.Size() << endl;
	cout << q.Front() << endl;

	q.Pop();

	cout << q.Size() << endl;
	cout << q.Front() << endl;
	cout << q.Back() << endl;

}
int main()
{

	//TestStack();
	TestQueue();
	system("pause");
	return 0;
}

