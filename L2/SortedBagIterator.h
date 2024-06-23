#pragma once
#include "SortedBag.h"
#include <stdexcept>

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag &bag;
	SortedBagIterator(const SortedBag &b);
	// TODO - Representation
	Node *current;
	int currentFreq;

public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
	int distinctCount() const;
};
