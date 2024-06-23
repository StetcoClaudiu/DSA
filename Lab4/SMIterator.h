#pragma once
#include "SortedMap.h"

#include <stdexcept>

// DO NOT CHANGE THIS PART
class SMIterator
{
	friend class SortedMap;

private:
	SMIterator(const SortedMap &mapionar);

	const SortedMap &map;
	TElem *sortedArray;
	int currentPosition;
	int sortedArraySize;

	// TODO - Representation

public:
	void first();
	void next();
	bool valid() const;
	TElem getCurrent() const;
};
