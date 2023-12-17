#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

int n, m;
char map[1010][1010];

int manyEmpty;
vector<pair<int, int> > emptyCell;

int dir[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

bool checkMapFull() {
    int checkInt, sumBom;
    char checkChar;
    printf("a");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            checkChar = map[i][j];
            if (!(47 < checkChar && checkChar < 58)) continue; // 48 = '0', 57 = '9'

            checkInt = checkChar - 48;
            sumBom = 0;

            for(int idxDir = 0; idxDir < 8; idxDir++) {
                int cX = i + dir[idxDir][0];
                int cY = j + dir[idxDir][1];

                if (!(cX >= 0 && cY >= 0 && cX < n && cY < m)) continue;
                if (map[cX][cY] == '*') sumBom++;
            }

            if (sumBom != checkInt) return false; // invalid
        }

    return true; // valid
}

bool binaryString(int idx) {
    bool res = false;

    if (idx == manyEmpty) return checkMapFull();
    else {
        int x = emptyCell[idx].first;
        int y = emptyCell[idx].second;

        // not bom
        map[x][y] = '-';
        res = res || binaryString(idx + 1);
        map[x][y] = '?';

        if (res) return res;

        // is bom
        map[x][y] = '*';
        res = res || binaryString(idx + 1);
        map[x][y] = '?';

        if (res) return res;
    }

    return res;
}

int main()
{
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c\n", &map[i][j]);
            if (map[i][j] == '?') emptyCell.push_back(make_pair(i, j));
        }

        map[i][m] = '\0';
    }

    manyEmpty = emptyCell.size();
    printf("%s\n", binaryString(0) ? "VALID" : "INVALID");
}