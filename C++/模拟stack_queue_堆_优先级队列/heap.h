#include "common.h"
					
template<class T>
class less
{
	bool operator()(const T& left, const T& right)
	{
		return left < right;
	}
};

template<class T>
class greater
{
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

template<class T, class compare = less<T>>
class heap
{
public:
				   
	heap()
	{}
	heap(const T* arr,size_t size)
	{
		heap.reserve(size);
		for (int i = 0; i < size; ++i)
		{
			heap.push_back(arr[i]);
		}
		for (int j = (heap.size() - 2) / 2; j >= 0; --j)
		{
			adjustdown(j);
		}
	}

	void push(const T& x)
	{
		heap.push_back(x);
		adiustup(heap.size() - 1);
	}
	void pop()
	{
		swap(heap[0],heap[heap.size()-1]);
		heap.pop_back();
		adjustdown(0);
	}
	const T& top()
	{
		return heap[0];

	}

	size_t size() const
	{
		return heap.size();
	}
	bool empty()
	{
		return heap.empty();
	}

	void insert(const T& data)
	{
		heap.push_back(data);
		adjustup(heap.size() - 1);
	}

	void remove()
	{
		swap(heap[0], heap[heap.size() - 1]);
		heap.pop_back();
		adjustdown(0);
	}


	void adjustdown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		while (child < heap.size())
		{
			if (child + 1 < heap.size() + 1 && heap[child] < heap[child + 1])
				child++;
			if (heap[parent] < heap[child])
			{
				swap(heap + child, heap + parent);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}

		}
	}
	void adjustup(size_t child )
	{
		size_t parent = child / 2; //Ç°Ìב for(int i = (n-2)/2;i<n;++i)
		while (child)
		{
			if (heap[parent] < heap[child])
			{
				swap(heap + child, heap + parent);
				parent = child;
				child = parent / 2;
			}
			else
			{
				break;
			}
		}

	}
private:
	vector<T> heap;

};
