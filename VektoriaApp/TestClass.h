#pragma once
#include <iostream>
#include <string>
#include <list>
#include "IClassID.h"
class TestClass : public IClassID
{
private:
	long _long;
	char _char;
	std::string _string;
	std::list<long> _list;
	long _longArray[1000];

public:
	TestClass();
	~TestClass();
	void print();
};

