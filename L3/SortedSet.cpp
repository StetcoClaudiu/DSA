#include "SortedSetIterator.h"
#include "SortedSet.h"
#include <stdexcept>

// Best case O(MAX_SIZE)
// Worst case O(MAX_SIZE)
// Average case O(MAX_SIZE)
SortedSet::SortedSet(Relation r)
{
	this->r = r;
	this->head = -1;
	this->length = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		nodes[i].elem = NULL_TELEM;
		nodes[i].next = -1;
	}
}

// Best case O(1)
// Worst case O(n)
// Average case O(n)
bool SortedSet::add(TComp elem)
{
	if (search(elem))
		return false;

		int newIndex = length;
	if (newIndex >= MAX_SIZE)
		throw std::overflow_error("Set is full");

	int prev = -1;
	int current = head;

	while (current != -1 && r(nodes[current].elem, elem))
	{
		prev = current;
		current = nodes[current].next;
	}

	nodes[newIndex].elem = elem;
	nodes[newIndex].next = current;

	if (prev == -1)
	{
		head = newIndex;
	}
	else
	{
		nodes[prev].next = newIndex;
	}

	length++;
	return true;
}

// Best case O(1)
// Worst case O(n)
// Average case O(n)
bool SortedSet::remove(TComp elem)
{
	if (!search(elem))
		return false;

	int prev = -1;
	int current = head;

	while (current != -1 && nodes[current].elem != elem)
	{
		prev = current;
		current = nodes[current].next;
	}

	if (current == -1)
		return false;

	if (prev == -1)
	{
		head = nodes[current].next;
	}
	else
	{
		nodes[prev].next = nodes[current].next;
	}

	nodes[current].elem = NULL_TELEM;
	nodes[current].next = -1;
	length--;
	return true;
}

// Best case O(1)
// Worst case O(n)
// Average case O(n)
bool SortedSet::search(TComp elem) const
{
	int current = head;
	while (current != -1)
	{
		if (nodes[current].elem == elem)
			return true;
		current = nodes[current].next;
	}
	return false;
}

// Best case O(1)
// Worst case O(1)
// Average case O(1)
int SortedSet::size() const
{
	return length;
}

// Best case O(1)
// Worst case O(1)
// Average case O(1)
bool SortedSet::isEmpty() const
{
	return length == 0;
}

// Best case O(1)
// Worst case O(1)
// Average case O(1)
SortedSetIterator SortedSet::iterator() const
{
	return SortedSetIterator(*this);
}

SortedSet::~SortedSet()
{
	// TODO - Implementation
}
