#pragma once
#include "Set.h"

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	SetIterator(const Set& s);

	//TODO - Representation
    int index;

public:
	void first();
	void next();
	TElem getCurrent();
    void modifyCurrent(TElem elem);
	bool valid() const;
};


