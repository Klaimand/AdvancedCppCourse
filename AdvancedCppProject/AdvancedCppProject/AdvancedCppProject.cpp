
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{

    string value;

    cout << typeid(value).name() << endl;


    return 0;
}
