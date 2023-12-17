#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;

    cin >> s;
    int test = s.find("_");

    if (test > -1)
    {
        int index = s.find("_");
        while (index > -1)
        {
            s.erase(index, 1);
            s[index] += 'A' - 'a';
            index = s.find("_");
        }
    }
    else
    {
        int loop = s.length();

        for (int i = 0; i < loop; i++)
        {
            if (64 < s[i] && s[i] < 91)
            {
                s.insert(i, "_");
                s[i + 1] += 'a' - 'A';
                loop++;
            }
        }
    }

    cout << s;

    return 0;
}