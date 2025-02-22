#ifndef BASE_H
#define BASE_H

template<typename T1, typename T2>
class Base
{
private:
	T1* _value1 = nullptr;
	T2* _value2 = nullptr;
public:
	Base() = delete;
	Base(const T1& value1, const T2& value2)
		: _value1(new T1(value1)), _value2(new T2(value2))
	{ CREATE_INFO("Base <- constructor: called"); }
	virtual ~Base()
	{
		CREATE_INFO("Base <- destructor: called");

		if (_value1) { delete _value1; }
		if (_value2) { delete _value2; }
	}

	virtual T1* getValue1() const { INFO("Base -> method getValue1: called;"); return _value1; }
	virtual T2* getValue2() const { INFO("Base -> method getValue2: called;"); return _value2; }

	virtual void setValue1(const T1& value) { INFO("Base -> method setValue1: called;"); if(_value1) {delete _value1; } _value1 = new T1(value); }
	virtual void setValue2(const T2& value) { INFO("Base -> method setValue2: called;"); if(_value2) {delete _value2; } _value2 = new T2(value); }
};

#endif