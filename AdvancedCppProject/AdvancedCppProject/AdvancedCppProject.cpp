
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fileName = "stats.txt";
    ifstream input;

    input.open(fileName);

    if (!input.is_open())
        return 1;

    while (input)
    {
        string line;

        getline(input, line, ':');

        int population = 0;

        input >> population;

        input >> ws;

        cout << "'" << line << "' -- '" << population << "'" << endl;
    }

    input.close();

    return 0;
}
