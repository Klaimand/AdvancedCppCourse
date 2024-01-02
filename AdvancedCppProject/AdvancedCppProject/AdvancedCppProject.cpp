
#include <iostream>
using namespace std;

void GoesWrong()
{
    bool bError1Detected = false;
    bool bError2Detected = true;

    if (bError1Detected)
    {
        throw bad_alloc();
    }

    if (bError2Detected)
    {
        throw exception();
    }
}

int main()
{
    try
    {
        GoesWrong();
    }
    catch (bad_alloc &e)
    {
        cout << "Catching bad alloc : " << e.what() << endl;
    }
    catch (exception &e)
    {
        cout << "Catching exception : " << e.what() << endl;
    }


    return 0;
}
