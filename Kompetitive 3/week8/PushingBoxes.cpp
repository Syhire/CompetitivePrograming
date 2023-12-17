#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
using namespace std;

int r, c;
char map[25][25];
pair<int, int> playerS; // player starting point
pair<int, int> boxS;    // box starting point
pair<int, int> finish;

// Node buat sekeliling Box
class Moves
{
public:
    int px;
    int py;
    int bx;
    int by;

    Moves(int _px, int _py, int _bx, int _by)
    {
        px = _px;
        py = _py;
        bx = _bx;
        by = _by;
    }
};

// Edge sekeliling Box
class EdgeMove
{
public:
    Moves *parent;
    Moves *curr;

    int walk;
    int push;

    string path;

    EdgeMove(Moves &_parent, Moves &_curr, int _walk, int _push, string _path)
    {
        parent = &_parent;
        curr = &_curr;
        walk = _walk;
        push = _push;
        path = _path;
    }

    EdgeMove(Moves &_curr, int _walk, int _push, string _path)
    {
        curr = &_curr;
        walk = _walk;
        push = _push;
        path = _path;
    }
};

class Node
{
public:
    int pX;
    int pY;
    int moves;
    string path;

    Node(int _pX, int _pY, int _moves, string _path)
    {
        pX = _pX;
        pY = _pY;
        moves = _moves;
        path = _path;
    }
};

int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // S, N, E, W
string dirChar[] = {"s", "n", "e", "w"};           // bawah, atas, kanan, kiri

void find_walk(EdgeMove &edge)
{
    queue<Node> q;
    bool visited[25][25] = {false};
    q.push(Node(edge.curr->bx, edge.curr->by, 0, edge.path));
    visited[edge.curr->bx][edge.curr->by] = true;

    int nbx = edge.curr->px;
    int nby = edge.curr->py;

    while (!q.empty())
    {
        Node f = q.front();
        q.pop();

        int fpx = f.pX;
        int fpy = f.pY;

        // if (visited[fpx][fpy][fbx][fby])
        //     continue;

        for (int i = 0; i < 4; i++)
        {
            int npx = fpx + dir[i][0];
            int npy = fpy + dir[i][1];

            // printf("-> %d %d %d %d (%s) [%d]\n", npx, npy, nbx, nby, f.path.c_str(), visited[npx][npy][nbx][nby]);

            if (npx == nbx && npy == nby)
                continue;
            if (visited[npx][npy] == true)
                continue;
            if (map[npx][npy] == '#')
                continue;
            if (npx < 0 || npy < 0 || npx > r || npy > c)
                continue;

            Node move = Node(npx, npy, f.moves + 1, f.path + dirChar[i]);
            if ((abs(npx - nbx) <= 1 && npy - nby == 0) || (abs(npy - nby) <= 1 && npx - nbx == 0))
                printf("=> %d %d %d %d (%s) [%d]\n", npx, npy, nbx, nby, move.path.c_str(), move.moves);
            visited[npx][npy] = true;
            q.push(move);
        }
    }
}

void find_push(pair<int, int> player, pair<int, int> box, string path)
{
}

// void find_moves(Moves m)
// {
//     queue<Moves> q;
//     q.push(Moves(m.px, m.py, m.bx, m.by));

//     // Make 4 tree ???
//     while (!q.empty())
//     {
//         Moves front = q.front();
//         q.pop();
//     }
// }

int main()
{
    while (scanf("%d %d\n", &r, &c) && r != 0 && c != 0)
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                scanf("%c\n", &map[i][j]);
                if (map[i][j] == 'S')
                    playerS = make_pair(i, j);
                if (map[i][j] == 'B')
                    boxS = make_pair(i, j);
                if (map[i][j] == 'T')
                    finish = make_pair(i, j);
            }

        for (int i = 0; i < r; i++)
            printf("%s\n", map[i]);

        printf("player: %d %d\n", playerS.first, playerS.second);
        printf("box: %d %d\n", boxS.first, boxS.second);

        Moves b = Moves(playerS.first, playerS.second, boxS.first, boxS.second);
        EdgeMove temp = EdgeMove(b, 0, 0, "");

        find_walk(temp);
        printf("%d\n", temp.curr->bx);
    }
}