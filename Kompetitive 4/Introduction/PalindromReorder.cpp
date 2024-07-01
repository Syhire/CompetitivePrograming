#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    char str[1000010];
    scanf("%s\n", str);

    int size = strlen(str);
    int freqs[100] = {0};
    vector<char> chars;

    for (int i = 0; i < size; i++)
    {
        freqs[str[i]]++;
        if (freqs[str[i]] == 1)
            chars.push_back(str[i]);
    }

    char evenChar = '\0';
    int oddFreq = 0;

    if (chars.size() == 1)
    {
        printf("%s\n", str);
        return 0;
    }

    for (int i = 0; i < chars.size() && oddFreq <= 1; i++)
    {
        int freq = freqs[chars[i]];
        // printf("%c (%d)\n", chars[i], freq);
        if (freq % 2 == 1)
        {
            oddFreq++;
            evenChar = chars[i];
        }
    }

    // printf("%d %d\n", isPossible, isThereOneEven);

    if (oddFreq > 1)
    {
        printf("NO SOLUTION\n");
        return 0;
    }

    int idx = 0;

    for (int i = 0; i < chars.size(); i++)
    {
        // printf("# %c\n", chars[i]);
        for (int j = 0; j < freqs[chars[i]] / 2; j++)
        {
            str[idx + j] = str[size - idx - j - 1] = chars[i];
            // printf("%d %d (%c)\n", idx + j, size - idx - j - 1, chars[i]);
        }
        idx += freqs[chars[i]] / 2;
        // printf("%d %d\n", freqs[chars[i]], idx);
        // printf("%d => %s\n", i, str);
    }

    if (size % 2 == 1)
        str[idx] = evenChar;
    printf("%s\n", str);
}