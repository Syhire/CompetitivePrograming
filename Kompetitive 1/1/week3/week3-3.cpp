#include <cstdio>
#include <cstring>

int main()
{
    char a[2050];

    scanf("%s", a);

    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == ':' || a[i] == ';')
            if (a[i + 1] == ')')
                printf("%d\n", i);
            else if (a[i + 1] == '-')
                if (a[i + 1] == ')')
                    printf("%d\n", i);
    }
}