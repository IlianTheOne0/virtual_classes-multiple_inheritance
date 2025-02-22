#ifndef CHILD2_H
#define CHILD2_H

#include "../Child2/child2.h"

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2
	: public Child<T1, T2, T3, T4>
{
private:
	T5* _value5 = nullptr;
	T6* _value6 = nullptr;
public:
	Child2() = delete;
	Child2(const T1& value1, const T2& value2, const T3& value3, const T4& value4, const T5& value5, const T6& value6)
		: Child<T1, T2, T3, T4>(value1, value2, value3, value4), _value5(new T5(value5)), _value6(new T6(value6))
	{ CREATE_INFO("Child2 <- constructor: called"); }
	~Child2() override
	{
		CREATE_INFO("Child2 <- destructor: called");

		if (_value5) { delete _value5; }
		if (_value6) { delete _value6; }
	}

	virtual T5* getValue5() const { INFO("Child2 -> method getValue5: called;"); return _value5; }
	virtual T6* getValue6() const { INFO("Child2 -> method getValue6: called;"); return _value6; }

	virtual void setValue5(const T5& value) { INFO("Child -> method setValue5: called;"); if(_value5) {delete _value5; } _value5 = new T5(value); }
	virtual void setValue6(const T6& value) { INFO("Child -> method setValue6: called;"); if(_value6) {delete _value6; } _value6 = new T6(value); }
};

#endif