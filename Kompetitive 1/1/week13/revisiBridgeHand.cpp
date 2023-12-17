#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int mapSimbol[256], mapNilai[256];

class Card
{
public:
    char text[3];
    // int simbol, nilai;
    int value;

    Card(char s, char n)
    {
        // simbol = mapSimbol[s];
        // nilai = '2' <= n && n <= '9' ? n - '0' : mapNilai[n];

        value = mapSimbol[s] * 15 + ('2' <= n && n <= '9' ? n - '0' : mapNilai[n]);

        text[0] = s;
        text[1] = n;
        text[2] = 0;
    }

    bool operator<(const Card &other) const;
};

int main()
{
    mapSimbol['C'] = 0;
    mapSimbol['D'] = 1;
    mapSimbol['S'] = 2;
    mapSimbol['H'] = 3;

    mapNilai['T'] = 10;
    mapNilai['J'] = 11;
    mapNilai['Q'] = 12;
    mapNilai['K'] = 13;
    mapNilai['A'] = 14;

    char s, n;
    char first;
    int i, j;

    // while (scanf("%c\n", &dealer) && dealer != '#')
    while (scanf("%c\n", &first), first != '#')
    {
        switch (first)
        {
        case 'N':
            j = 3;
            break;
        case 'E':
            j = 0;
            break;
        case 'S':
            j = 1;
            break;
        case 'W':
            j = 2;
            break;
        }

        vector<Card> hand[4];

        for (i = 0; i < 52; i++)
        {
            scanf("%c%c\n", &s, &n);
            hand[j].push_back(Card(s, n));

            j = (j + 1) % 4;
        }

        char arr[] = {'S', 'W', 'N', 'E'};

        for (j = 0; j < 4; j++, printf("\n"))
        {
            printf("%c:", arr[j]);
            sort(hand[j].begin(), hand[j].end());
            for (i = 0; i < hand[j].size(); i++)
                printf(" %s", hand[j][i].text);
        }
    }

    return 0;
}

bool Card::operator<(const Card &other) const
{
    // if (simbol == other.simbol)
    //     return nilai < other.nilai;
    // return simbol < other.simbol;

    return value < other.value;
}