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
	class iterator;
	
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

	iterator begin()
	{
		return iterator(0, *this);
	}

	iterator end()
	{
		return iterator(size, *this);
	}

};

template<class T>
class Ring<T>::iterator
{
private:
	int index;
	Ring ring;

	
public:
	iterator(const int &index_, Ring<T> &ring_)
	{
		index = index_;
		ring = ring_;
	}

	iterator &operator++(int)
	{
		index++;

		return *this;
	}

	iterator &operator++()
	{
		index++;

		return *this;
	}

	T &operator*()
	{
		return ring.Get(index);
	}

	bool operator!=(const iterator &other) const
	{
		return other.index != index;
	}
	
};
