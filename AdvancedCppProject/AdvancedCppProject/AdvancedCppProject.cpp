
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool match(string test)
{
    return test.size() == 3;
}

template<typename T, typename K>
int countIf(T begin, T end, bool (*fn)(K))
{
    int i = 0;
    for (T it = begin; it != end; it++)
    {
        if (fn(*it))
            i++;
    }

    return i;
}

int main()
{

    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("four");
    //texts.push_back("two");
    texts.push_back("three");

    //cout << match("oned") << endl;

    //cout << count_if(texts.begin(), texts.end(), match) << endl;
    cout << countIf(texts.begin(), texts.end(), match) << endl;

    return 0;
}
