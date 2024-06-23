#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>

// Best case T(1)
// Worst case T(1)
// Average case O(1)
SortedBag::SortedBag(Relation r)
{
	// TODO - Implementation
	this->rel = r;
	this->head = nullptr;
	this->Size = 0;
}

// Best case T(1)
// Worst case T(n)
// Average case O(n)
void SortedBag::add(TComp e)
{
	// TODO - Implementation
	Node *previous = nullptr;
	Node *current = this->head;
	while (current != nullptr && this->rel(current->element, e))
	{
		if (current->element == e)
		{
			current->frequency++;
			this->Size++;
			return;
		}
		previous = current;
		current = current->next;
	}
	Node *newNode = new Node();
	newNode->element = e;
	newNode->next = current;
	newNode->frequency = 1;
	this->Size++;

	if (previous == nullptr)
	{
		this->head = newNode;
	}
	else
	{
		previous->next = newNode;
	}
}

// Best case T(1)
// Worst case T(n)
// Average case O(n)
bool SortedBag::remove(TComp e)
{
	// TODO - Implementation
	Node *previous = nullptr;
	Node *current = this->head;
	while (current != nullptr && this->rel(current->element, e))
	{
		if (current->element == e)
		{
			if (current->frequency > 1)
			{
				current->frequency--;
			}
			else if (current == this->head)
			{
				this->head = current->next;
			}
			else
			{
				previous->next = current->next;
			}
			this->Size--;
			return true;
		}
		previous = current;
		current = current->next;
	}
	return false;
}

// Best case T(1)
// Worst case T(n)
// Average case O(n)
bool SortedBag::search(TComp elem) const
{
	// TODO - Implementation
	Node *current = this->head;
	while (current != nullptr && this->rel(current->element, elem))
	{
		if (current != nullptr && current->element == elem)
			return true;
		current = current->next;
	}
	return false;
}

// Best case T(1)
// Worst case T(n)
// Average case O(n)
int SortedBag::nrOccurrences(TComp elem) const
{
	// TODO - Implementation
	Node *current = this->head;
	while (current != nullptr && this->rel(current->element, elem))
	{
		if (current->element == elem)
		{
			return current->frequency;
		}
		current = current->next;
	}
	return 0;
}

// Best case T(1)
// Worst case T(1)
// Average case O(1)
int SortedBag::size() const
{
	// TODO - Implementation
	return this->Size;
}

// Best case T(1)
// Worst case T(1)
// Average case O(1)
bool SortedBag::isEmpty() const
{
	// TODO - Implementation
	if (this->Size == 0)
		return true;
	return false;
}

// Best case T(1)
// Worst case T(1)
// Average case O(1)
SortedBagIterator SortedBag::iterator() const
{
	return SortedBagIterator(*this);
}

SortedBag::~SortedBag()
{
	// TODO - Implementation
}
