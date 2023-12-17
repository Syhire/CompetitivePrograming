#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Sentence
{
public:
    string sentenceUpper;
    string sentenceDown;
    string word;
    int orderBy;
    int orderBySentence;

    Sentence(string _sentenceUpper, string _sentence, string _word, int order, int orderSentence, int orderSplit)
    {
        sentenceUpper = _sentenceUpper;
        sentenceDown = _sentence.substr(orderSplit + _word.length());
        word = _word;
        orderBy = order;
        orderBySentence = orderSentence;
    }

    bool operator<(const Sentence &other) const
    {
        if (strcmp(word.c_str(), other.word.c_str()) == 0)
            return orderBy == other.orderBy ? orderBySentence < other.orderBySentence : orderBy < other.orderBy;

        return strcmp(word.c_str(), other.word.c_str()) < 0;
    }

    void printString()
    {
        printf("%s%s%s", sentenceUpper.c_str(), word.c_str(), sentenceDown.c_str());
        printf("\n");
    }
};

int main()
{
    char wordIgnoreInput[15];
    vector<string> wordIgnore;

    while (scanf("%s\n", &wordIgnoreInput) && wordIgnoreInput[0] != ':' && wordIgnoreInput[1] != ':')
    {
        string temp = wordIgnoreInput;
        wordIgnore.push_back(temp);
    }

    char strInput[10010];
    vector<Sentence> vecSentence;
    int indexOrder = 0;

    while (scanf("%[^\n]\n", &strInput) != EOF)
    {
        string temp = strInput;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        strcpy(strInput, temp.c_str());

        string cumulativeString;

        // printf("%d: %s\n", indexOrder, strInput);

        char *pointerWord = strtok(strInput, " ");

        int indexOrderSentence = 0;
        while (pointerWord != NULL)
        {
            if (find(wordIgnore.begin(), wordIgnore.end(), pointerWord) == wordIgnore.end())
            {
                string word = pointerWord;
                transform(word.begin(), word.end(), word.begin(), ::toupper);
                vecSentence.push_back(Sentence(cumulativeString, temp, word, indexOrder, indexOrderSentence, cumulativeString.length()));
                indexOrderSentence++;
            }

            cumulativeString = cumulativeString + pointerWord + " ";
            // printf("word: %s %d\n", cumulativeString.c_str(), cumulativeString.length());

            pointerWord = strtok(NULL, " ");
        }

        indexOrder++;
    }

    sort(vecSentence.begin(), vecSentence.end());

    for (int i = 0; !vecSentence.empty(); i++)
    {
        vecSentence[i].printString();
        vecSentence.pop_back();
    }
}