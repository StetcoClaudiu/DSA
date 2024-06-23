#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <iostream>
using namespace std;

SMIterator::SMIterator(const SortedMap &m) : map(m), currentPosition(0)
{
	sortedArraySize = map.size();
	sortedArray = new TElem[sortedArraySize];

	int index = 0;
	for (int i = 0; i < map.capacity; ++i)
	{
		if (map.occupied[i])
		{
			sortedArray[index++] = map.table[i];
		}
	}

	std::sort(sortedArray, sortedArray + sortedArraySize, [this](const TElem &a, const TElem &b)
			  { return map.relation(a.first, b.first); });
}

// T(1)
void SMIterator::first()
{
	currentPosition = 0;
	// TODO - Implementation
}

// T(1)
void SMIterator::next()
{
	// TODO - Implementation

	if (valid())
	{
		currentPosition++;
	}
	else
	{
		throw std::out_of_range("Iterator out of range");
	}
}

// T(1)
bool SMIterator::valid() const
{
	// TODO - Implementation
	return currentPosition < sortedArraySize;
}

// T(1)
TElem SMIterator::getCurrent() const
{
	if (!valid())
	{
		throw std::out_of_range("Iterator out of range");
	}
	return sortedArray[currentPosition];
}
