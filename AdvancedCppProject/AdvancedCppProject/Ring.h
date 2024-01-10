#pragma once
using namespace std;
#include <vector>


template <class T>
class Ring
{
	int curIndex = 0;
	int size = 0;

	T *items;

public:
	Ring() = default;

	Ring(int size_)
	{
		size = size_;
		items = new T[size];
	}

	~Ring()
	{
		delete [] items;
	}
	
	void Add(const T &obj)
	{
		items[curIndex] = obj;
		
		curIndex++;
		curIndex = curIndex % size;
	}

	T &Get(const int &index) const
	{
		return items[index];
	}

	int Size() const
	{
		return size;
	}

};

