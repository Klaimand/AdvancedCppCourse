
#include <iostream>
using namespace std;

class Test
{
private:
    int id;
    string name;

public:
    Test() = default;

    Test(int id_, string name_)
    {
        id = id_;
        name = name_;
    }

    Test& operator = (const Test& other)
    {
        id = other.id;
        name = other.name;

        return *this;
    }

    Test(const Test& other)
    {
        id = other.id;
        name = other.name;
    }

    friend ostream& operator << (ostream& out, const Test& test)
    {
        out << test.id << " : " << test.name;
        return out;
    }
};

int main()
{

    Test test1(10, "Mike");
    Test test2(20, "Bob");

    cout << test1 << endl;

    return 0;
}
