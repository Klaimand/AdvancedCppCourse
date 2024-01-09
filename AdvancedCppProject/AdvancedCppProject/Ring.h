#pragma once
using namespace std;
#include <vector>


template <class T>
class Ring
{
	int curIndex = 0;
	int size = 0;

	std::vector<T> items;

public:
	Ring() = default;

	Ring(int size_)
	{
		size = size_;
	}

	void Add(const T &obj)
	{
		if (items.size() < size)
		{
			items.push_back(obj);
		}
		else
		{
			items[curIndex] = obj;
		}

		curIndex++;
		curIndex = curIndex % size;
	}

	T Get(const int &index) const
	{
		return items[index];
	}

	int Size() const
	{
		return size;
	}

};

