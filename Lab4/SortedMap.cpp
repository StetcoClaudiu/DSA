#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <iostream>
using namespace std;

// Best case O(1), Worst case O(log^2n),  Average case O(log^2n)
int nextPrime(int n)
{
	while (true)
	{
		bool isPrime = true;
		for (int i = 2; i <= std::sqrt(n); ++i)
		{
			if (n % i == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			return n;
		}
		++n;
	}
}

// T(1)
int SortedMap::hash1(TKey key) const
{
	return abs(key) % capacity;
}

// T(1)
int SortedMap::hash2(TKey key) const
{
	return 1 + (abs(key) % (capacity - 1));
}

// T(1)
SortedMap::SortedMap(Relation r)
{
	capacity = 7;
	relation = r;
	Size = 0;
	loadFactor = 0.7;
	table = new TElem[capacity]();
	occupied = new bool[capacity]();
	// TODO - Implementation
}

// T(1)

Relation SortedMap::getRelation() const
{
	return relation;
}

// T(1)

TElem *SortedMap::getTable() const
{
	return table;
}

// T(1)

bool *SortedMap::getOccupied() const
{
	return occupied;
}

// Best case O(1),
void SortedMap::resizeAndRehash()
{
	int oldCapacity = capacity;
	capacity = nextPrime(2 * capacity);
	TElem *newTable = new TElem[capacity];
	bool *newOccupied = new bool[capacity]();

	for (int i = 0; i < oldCapacity; ++i)
	{
		if (occupied[i])
		{
			TKey key = table[i].first;
			TValue value = table[i].second;
			int hash = hash1(key);
			int step = hash2(key);
			int pos = hash;

			while (newOccupied[pos])
			{
				pos = (pos + step) % capacity;
			}

			newTable[pos] = {key, value};
			newOccupied[pos] = true;
		}
	}

	delete[] table;
	delete[] occupied;

	table = newTable;
	occupied = newOccupied;
}

// Best case O(1),
TValue SortedMap::add(TKey k, TValue v)
{
	if (static_cast<float>(Size) / capacity > loadFactor)
	{
		resizeAndRehash();
	}

	int hash = hash1(k);
	int step = hash2(k);
	int pos = hash;

	while (occupied[pos])
	{
		if (table[pos].first == k)
		{
			TValue oldValue = table[pos].second;
			table[pos].second = v;
			return oldValue;
		}
		pos = (pos + step) % capacity;
	}

	table[pos] = {k, v};
	occupied[pos] = true;
	Size++;

	return NULL_TVALUE;
}

// Best case O(1), Average case O(1), Worst case O(n);
TValue SortedMap::search(TKey k) const
{
	int hash = hash1(k);
	int step = hash2(k);
	int pos = hash;

	int initialPos = pos;

	while (occupied[pos])
	{
		if (table[pos].first == k)
		{
			return table[pos].second;
		}
		pos = (pos + step) % capacity;
		if (pos == initialPos)
		{
			break;
		}
	}
	return NULL_TVALUE;
}

// Best case O(1), Average case O(1), Worst case O(n);
TValue SortedMap::remove(TKey k)
{
	int hash = hash1(k);
	int step = hash2(k);
	int pos = hash;

	while (occupied[pos])
	{
		if (table[pos].first == k)
		{
			TValue oldValue = table[pos].second;
			occupied[pos] = false;
			--Size;
			return oldValue;
		}
		pos = (pos + step) % capacity;
	}

	return NULL_TVALUE;
}

// T(1)
int SortedMap::size() const
{
	// TODO - Implementation
	return Size;
}
// T(1)
bool SortedMap::isEmpty() const
{
	if (Size == 0)
		return true;
	// TODO - Implementation
	return false;
}
// T(1)
SMIterator SortedMap::iterator() const
{
	return SMIterator(*this);
}

SortedMap::~SortedMap()
{
	// TODO - Implementation
}
