#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Card
{
public:
    char suit;
    char number;

    Card(char _suit, char _number)
    {
        suit = _suit;
        number = _number;
    }

    bool operator<(const Card &o) const;
};

int main()
{
    char dealer;
    int dealerNum;

    vector<Card> North; // 0
    vector<Card> East;  // 1
    vector<Card> South; // 2
    vector<Card> West;  // 3

    char inputSuit, inputNumber;

    // while (scanf("%c\n", &dealer) && dealer != '#')
    while (scanf("%c\n", &dealer), dealer != '#')
    {
        if (dealer == 'N')
            dealerNum = 1;
        else if (dealer == 'E')
            dealerNum = 2;
        else if (dealer == 'S')
            dealerNum = 3;
        else
            dealerNum = 0;

        for (int i = 0; i < 52; i++)
        {
            scanf("%c%c\n", &inputSuit, &inputNumber);
            Card temp(inputSuit, inputNumber);

            if (dealerNum == 0)
                North.push_back(temp);
            else if (dealerNum == 1)
                East.push_back(temp);
            else if (dealerNum == 2)
                South.push_back(temp);
            else if (dealerNum == 3)
                West.push_back(temp);

            // printf("%d: %c%c\n", dealerNum, inputSuit, inputNumber);
            dealerNum = (dealerNum + 1) % 4;
        }

        sort(North.begin(), North.end());
        sort(East.begin(), East.end());
        sort(South.begin(), South.end());
        sort(West.begin(), West.end());

        printf("S:");
        for (int i = 0; i < South.size(); i++)
            printf(" %c%c", South[i].suit, South[i].number);

        printf("\nW:");
        for (int i = 0; i < West.size(); i++)
            printf(" %c%c", West[i].suit, West[i].number);

        printf("\nN:");
        for (int i = 0; i < North.size(); i++)
            printf(" %c%c", North[i].suit, North[i].number);

        printf("\nE:");
        for (int i = 0; i < East.size(); i++)
            printf(" %c%c", East[i].suit, East[i].number);

        printf("\n");

        North.clear();
        East.clear();
        West.clear();
        South.clear();
    }

    return 0;
}

int numSuit(char suit)
{
    switch (suit)
    {
    case 'C':
        return 1;
    case 'D':
        return 2;
    case 'S':
        return 3;
    case 'H':
        return 4;
    default:
        return 0;
    }
}

int numNumber(char number)
{
    switch (number)
    {
    case '2':
        return 1;
    case '3':
        return 2;
    case '4':
        return 3;
    case '5':
        return 4;
    case '6':
        return 5;
    case '7':
        return 6;
    case '8':
        return 7;
    case '9':
        return 8;
    case 'T':
        return 9;
    case 'J':
        return 10;
    case 'Q':
        return 11;
    case 'K':
        return 12;
    case 'A':
        return 13;
    default:
        return 0;
    }
}

bool Card::operator<(const Card &o) const
{
    int cardSuit = numSuit(suit);
    int cardNum = numNumber(number);
    int oSuit = numSuit(o.suit);
    int oNum = numNumber(o.number);

    return cardSuit == oSuit ? cardNum < oNum : cardSuit < oSuit;
}