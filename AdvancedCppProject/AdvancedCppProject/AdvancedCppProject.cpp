
#include <iostream>
#include <fstream>
using namespace std;


#pragma pack(push, 1)
struct Person
{
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)

int main()
{
    Person someone = {"Frodo", 220, 0.8f};

    string fileName = "test.bin";

    //write
    ofstream outputFile;

    outputFile.open(fileName, ios::binary);

    if (!outputFile.is_open())
        return 1;

    outputFile.write(reinterpret_cast<char*>(&someone), sizeof(Person));

    outputFile.close();




    //read

    Person someoneElse;

    ifstream inputFile;

    inputFile.open(fileName, ios::binary);

    if (!inputFile.is_open())
        return 1;

    inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));

    inputFile.close();

    cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << endl;

    return 0;
}
