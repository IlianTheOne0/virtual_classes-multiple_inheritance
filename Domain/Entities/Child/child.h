#ifndef CHILD_H
#define CHILD_H

#include "../Base/base.h"

template<typename T1, typename T2, typename T3, typename T4>
class Child
	: public Base<T1, T2>
{
private:
	T3* _value3 = nullptr;
	T4* _value4 = nullptr;
public:
	Child() = delete;
	Child(const T1& value1, const T2& value2, const T3& value3, const T4& value4)
		: Base<T1, T2>(value1, value2), _value3(new T3(value3)), _value4(new T4(value4))
	{ CREATE_INFO("Child <- constructor: called"); }
	~Child() override
	{
		CREATE_INFO("Child <- destructor: called");

		if (_value3) { delete _value3; }
		if (_value4) { delete _value4; }
	}

	virtual T3* getValue3() { INFO("Child -> method getValue3: called;"); return _value3; }
	virtual T4* getValue4() { INFO("Child -> method getValue4: called;"); return _value4; }

	virtual void setValue3(const T3& value) { INFO("Child -> method setValue3: called;"); if(_value3) {delete _value3; } _value3 = new T3(value); }
	virtual void setValue4(const T4& value) { INFO("Child -> method setValue4: called;"); if(_value4) {delete _value4; } _value4 = new T4(value); }
};

#endif