
#include <iostream>
#include "Ring.h"
using namespace std;




int main()
{

    Ring<string> textRing(3);

    textRing.Add("one");
    textRing.Add("two");
    textRing.Add("three");
    textRing.Add("four");
    textRing.Add("five");

    for (int i = 0; i < textRing.Size(); i++)
    {
        cout << textRing.Get(i) << endl;
    }

    return 0;
}
