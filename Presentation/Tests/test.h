#ifndef TEST_H
#define TEST_H

#include "../View/view.h"

class Test
{
private:
	static const unsigned short testCounter;
public:
	static void exampleTest();

	static void startTest()
	{
		switch (testCounter)
		{
			case 0: { exampleTest(); } break;
			default: { View::Intro0(); }
		}
	}
};

#endif