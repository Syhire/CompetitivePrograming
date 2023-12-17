#include <stdio.h>
#include <vector>
#include <algorithm>  // sort
#include <functional> // greater
using namespace std;

class Point
{
public:
    int x, y;

    Point()
    {
        x = y = 0;
    }

    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    Point(int a)
    {
        x = y = a;
    }

    // overloading operator <
    // const pertama buat other ga bisa di ubah
    // const kedua buat object kita ga bisa diubah
    bool operator<(const Point &other) const
    {
        return x == other.x ? y < other.y : x < other.x;
    }

    bool operator>(const Point &other) const
    {
        return x == other.x ? y > other.y : x > other.x;
    }
};

int main()
{
    vector<Point> vc;

    /*
    cara 1: byat dulu object baru di copy ke dalam vector
    Point temp(5, 7);
    vc.push_back(temp); // 5, 7
    temp.x = 3; temp.y = 10;
    vc.push_back(temp); // 3, 10
    */

    // cara 2: langsung buat tetapi masih di buat dan di copy tapi lebih rapih
    vc.push_back(Point(5, 7));
    vc.push_back(Point(3, 10));
    vc.push_back(Point(1, 8));
    vc.push_back(Point(4, 4));
    vc.push_back(Point(2, 6));
    vc.push_back(Point(1, 10));
    vc.push_back(Point(2, 8));
    vc.push_back(Point(3, 5));

    sort(vc.begin(), vc.end(), greater<Point>());

    for (int i = 0; i < vc.size(); i++)
    {
        printf("(%d, %d) ", vc[i].x, vc[i].y);
    }

    return 0;
}