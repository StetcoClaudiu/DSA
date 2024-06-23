#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

// Best case T(1)
// Worst case T(1)
// Average case O(1)
SortedBagIterator::SortedBagIterator(const SortedBag &b) : bag(b)
{
	// TODO - Implementation
	current = bag.head;
	currentFreq = 1;
}

// Best case T(1)
// Worst case T(1)
// Average case O(1)
TComp SortedBagIterator::getCurrent()
{
	// TODO - Implementation
	if (current == nullptr)
		throw std::out_of_range("Iterator is not valid");

	return current->element;
}

// Best case T(1)
// Worst case T(1)
// Average case O(1)
bool SortedBagIterator::valid()
{
	// TODO - Implementation
	if (this->current != nullptr)
		return true;
	return false;
}

// Best case T(1)
// Worst case T(1)
// Average case O(1)
void SortedBagIterator::next()
{
	// TODO - Implementation
	if (current == nullptr)
		throw std::out_of_range("Iterator is not valid");
	if (this->currentFreq < current->frequency)
	{
		this->currentFreq++;
	}
	else
	{
		this->currentFreq = 1;
		current = current->next;
	}
}

// Best case T(1)
// Worst case T(1)
// Average case O(1)
void SortedBagIterator::first()
{
	this->current = bag.head;
	// TODO - Implementation
}

int SortedBagIterator::distinctCount() const
{
	SortedBagIterator it = *this;
	it.first();
	it.currentFreq = INT_MAX;
	int counter = 0;
	while (it.valid())
	{
		counter++;
		it.currentFreq = INT_MAX;
		it.next();
	}
	return counter;
}