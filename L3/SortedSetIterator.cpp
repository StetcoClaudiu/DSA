#include "SortedSetIterator.h"
#include <stdexcept>

using namespace std;

// Best case O(1)
// Worst case O(1)
// Average case O(1)
SortedSetIterator::SortedSetIterator(const SortedSet &m) : multime(m)
{
	current = multime.head;
}

// Best case O(1)
// Worst case O(1)
// Average case O(1)
void SortedSetIterator::first()
{
	current = this->multime.head;
}

// Best case O(1)
// Worst case O(1)
// Average case O(1)
void SortedSetIterator::next()
{
	if (!valid())
	{
		throw std::out_of_range("Iterator is not valid");
	}
	current = this->multime.nodes[current].next;
}

// Best case O(1)
// Worst case O(1)
// Average case O(1)
TComp SortedSetIterator::getCurrent()
{
	if (!valid())
	{
		throw std::out_of_range("Iterator is not valid");
	}
	return this->multime.nodes[current].elem;
}

// Best case O(1)
// Worst case O(1)
// Average case O(1)
bool SortedSetIterator::valid() const
{
	return current != -1;
}
