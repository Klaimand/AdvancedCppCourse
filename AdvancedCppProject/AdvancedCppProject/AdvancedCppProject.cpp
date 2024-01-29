
#include <iostream>
#include <memory>
using namespace std;


class Test
{
public:
    Test()
    {
        cout << "created" << endl;
    }

    void greet()
    {
        cout << "Hello" << endl;
    }

    ~Test()
    {
        cout << "Delete" << endl;
    }
};

int main()
{

    shared_ptr<Test> pTest = make_shared<Test>();



    cout << "Finished" << endl;


    return 0;
}
