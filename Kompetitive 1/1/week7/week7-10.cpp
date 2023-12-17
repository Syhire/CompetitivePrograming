#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d\n", &n);

    int sama = 0, beda = 0;

    char me[1001];
    char you[1001];

    scanf("%[^\n]\n", me);
    scanf("%[^\n]\n", you);

    int i;
    int length = strlen(me);

    for (i = 0; i < length; i++)
        if (me[i] == you[i])
            sama++;
        else
            beda++;

    int output = 0;

    if (sama >= n)
        output += n;
    else
        output += sama;

    if (beda >= length - n)
        output += length - n;
    else
        output += beda;

    printf("%d\n", output);
}