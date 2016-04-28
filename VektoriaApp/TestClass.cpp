#include "TestClass.h"
#include <cstdio>



TestClass::TestClass()
{
	_classID = 7357;
	_long = 0xffffffffffffffff;
	_string = "this is a test";
	for (int i = 0; i < 100; i++)
	{
		_list.push_front(i * 1000);
	}
	for (int i = 0; i < 1000;i++)
	{
		_longArray[i] = i;
	}
}


TestClass::~TestClass()
{
}

void TestClass::print()
{
	std::cout << "Long:" << _long << std::endl;
	std::cout << "char:" << _char << std::endl;
	std::cout << "String:" << _string << std::endl;
	for(auto value : _list)
	{
		std::cout << value << std::endl;
	}

	for (int i = 0; i < 1000;i++)
	{
		std::cout << _longArray[i] << std::endl;
	}


	for (int i = 0; i < sizeof(TestClass);i+=8)
	{
		for (int j = i; j < i + 4;j++)
		{
			printf("%X ", _longArray[j]);
		}
		printf("   ");

		for (int j = i; j < i + 4; j++)
		{
			printf("%X ", _longArray[j]);
		}
		printf("\n");
	}
}
