#include <cstdio>
#include <cstring>

int rec(int n)
{
    return n <= 2 ? n : n * rec(n - 1);
}

int main()
{
    int n;

    scanf("%d", &n);

    int a = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);

        printf("%d", rec(a) % 10);
    }
}
