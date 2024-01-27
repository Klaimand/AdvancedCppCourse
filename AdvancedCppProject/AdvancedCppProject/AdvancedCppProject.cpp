
#include <iostream>
using namespace std;

void test(void (*f)())
{
    f();
}

int main()
{

    auto func = []() { cout << "Hello" << endl; };

    func();

    test(func);

    return 0;
}
