#include <cstdio>

int main()
{
    int n;

    scanf("%d", &n);

    int b;
    double p;

    for (int i = 0; i < n; i++)
    {
        scanf("%d %lf\n", &b, &p);
        double bpm = (60.0 * b) / p;
        double abpm = 60.0 / p;

        printf("%.4f %.4f %.4f\n", bpm - abpm, bpm, bpm + abpm);
    }
}