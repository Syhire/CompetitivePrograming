#include <stdio.h>
#include <string>
#include <map>
using namespace std;

int n, m, k;
string goldenTick[110];
// string topTeams[110];
map<string, string> teams; // institude, team
map<string, bool> isValid; // institude, got golden tick

int main()
{
    scanf("%d %d %d\n", &n, &m, &k);

    int top = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        char institude[15], team[15];
        scanf("%s %s\n", team, institude);
        // printf("#%d %s %s\n", i, institude, team);

        if (i < m)
            isValid[institude] = true;

        if (teams.find(institude) == teams.end()) // new institude
            teams[institude] = team;

        // printf("%d < %d (%d & %d)\n", sum, m, sum < m, !isValid[institude]);

        if (sum < k && !isValid[institude])
        {
            isValid[institude] = true;
            goldenTick[sum++] = teams[institude];
            // printf("%s\n", teams[institude].c_str());
        }
    }

    if (sum == 0)
        printf("%d", sum);
    else
        printf("%d\n", sum);

    for (int i = 0; i < sum; i++)
    {
        if (i == 0)
            printf("%s", goldenTick[i].c_str());
        else
            printf("\n%s", goldenTick[i].c_str());
    }
}