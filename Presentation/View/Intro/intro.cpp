#include "../view.h"
#include "../../../Domain/domain.h"

void printValues(Child2<int, string, double, char, bool, const char*>* value)
{
    cout << "Base: Value1: " << *(value->getValue1()) << endl;
    cout << "Base: Value2: " << *(value->getValue2()) << endl;
    cout << "Child: Value3: " << *(value->getValue3()) << endl;
    cout << "Child: Value4: " << *(value->getValue4()) << endl;
    cout << "Child2: Value5: " << *(value->getValue5()) << endl;
    cout << "Child2: Value6: " << *(value->getValue6()) << endl;
}

void setValues(Child2<int, string, double, char, bool, const char*>* value)
{
    value->setValue1(200);
    value->setValue2("Updated string");
    value->setValue3(199.9);
    value->setValue4('B');
    value->setValue5(false);
    value->setValue6("Updated world!");
}

void View::Intro0()
{
    Child2<int, string, double, char, bool, const char*>* value0 =
        new Child2<int, string, double, char, bool, const char*>(100, "Hello world!", 99.9, 'A', true, "Bye world!");

    printValues(value0); cout << endl;
    setValues(value0); cout << endl;
    printValues(value0); cout << endl;

    delete value0;
}