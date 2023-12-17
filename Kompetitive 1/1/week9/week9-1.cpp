#include <stdio.h>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    int count, countIdx;

    scanf("%d\n", &count);

    for (countIdx = 0; countIdx < count; countIdx++)
    {
        char input[101];
        // printf("%d: ", countIdx + 1);
        scanf("%[^\n]\n", input);

        // bool letters[26] = {false};
        map<char, bool> letters;
        int count = 0;

        for (int i = 0; i < strlen(input); i++)
        {
            if (input[i] < 'a')
                input[i] = input[i] - 'A' + 'a';

            if ('a' <= input[i] && input[i] <= 'z')
            {
                // printf("%d %d\n", input[i] - 'a', letters[input[i] - 'a']);
                if (!letters[input[i]])
                {
                    letters[input[i]] = true;
                    count++;
                }
            }
        }

        if (count == 26)
        {
            printf("pangram\n");
            continue;
        }

        printf("missing ");

        for (char i = 'a'; i <= 'z'; i++)
            if (!letters[i])
                printf("%c", i);
        printf("\n");
    }
}