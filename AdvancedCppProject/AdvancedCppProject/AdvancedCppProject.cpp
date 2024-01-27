
#include <iostream>
#include "Bitmap.h"

using namespace std;

int main()
{

    Bitmap bitmap(800, 600);

    if (bitmap.write("test.bmp"))
    {
        cout << "Finished" << endl;
    }
    else
    {
        cout << "Problem" << endl;
    }


    return 0;
}
