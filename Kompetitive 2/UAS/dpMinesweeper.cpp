#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

int n, m;
char map[1010][1010];

int manyEmpty;
vector<pair<int, int> > emptyCell;

int dir[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

int sumOfSurounding(int x, int y) {
    int sumBom = 0;

    for(int idxDir = 0; idxDir < 8; idxDir++) {
        int cX = x + dir[idxDir][0];
        int cY = y + dir[idxDir][1];

        if (!(cX >= 0 && cY >= 0 && cX < n && cY < m)) continue;
        if (map[cX][cY] == '*') sumBom++;
    }

    return sumBom;
}

bool checkMapFull() {
    int checkInt, sumBom;
    char checkChar;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            checkChar = map[i][j];
            if (!(47 < checkChar && checkChar < 58)) continue; // 48 = '0', 57 = '9'

            checkInt = checkChar - 48; // turn char into int
            sumBom = sumOfSurounding(i, j);

            // printf("-> %d %d: %d\n", i, j, sumBom);

            if (sumBom != checkInt) return false; // invalid
        }

    return true; // valid
}

bool checkMap(int x, int y) {
    int checkInt, sumBom;
    char checkChar;

    for(int idxDir = 0; idxDir < 8; idxDir++) {
        int cX = x + dir[idxDir][0];
        int cY = y + dir[idxDir][1];

        if (!(cX >= 0 && cY >= 0 && cX < n && cY < m)) continue;
        checkChar = map[cX][cY];
        if (!(47 < checkChar && checkChar < 58)) continue;

        checkInt = checkChar - 48;
        sumBom = sumOfSurounding(cX, cY);

        if (sumBom > checkInt) return false;
    }

    return true;
}

bool binaryString(int idx) {
    bool res = false;

    if (res) return res;

    if (idx == manyEmpty) {
        // for (int i = 0; i < n; i++)
        //     printf("%s\n", map[i]);
        
        // printf("hasil: %d\n", checkMapFull());

        return checkMapFull();
    } 
    else {
        int x = emptyCell[idx].first;
        int y = emptyCell[idx].second;

        // not bom
        map[x][y] = '-';
        if (checkMap(x, y)) res = res || binaryString(idx + 1);
        map[x][y] = '?';

        // is bom
        map[x][y] = '*';
        if (checkMap(x, y)) res = res || binaryString(idx + 1);
        map[x][y] = '?';
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

    // for (int i = 0; i < n; i++)
    //     printf("%s\n", map[i]);

    // for (int i = 0; i < manyEmpty; i++)
    //     printf("%d %d\n", emptyCell[i].first, emptyCell[i].second);

    // printf("%d\n", checkMapFull());
}