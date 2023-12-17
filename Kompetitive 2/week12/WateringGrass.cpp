#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double l, w;

bool compare(const pair<double, double> &a, const pair<double, double> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    while (scanf("%d %lf %lf\n", &n, &l, &w) != EOF)
    {
        double w2 = w / 2.0;
        double r, middle;
        vector<pair<double, double> > arr;

        while (n--)
        {
            scanf("%lf %lf\n", &middle, &r);
            if (r < w2) continue;
            double temp = sqrt(r * r - w2 * w2);
            arr.push_back(make_pair(middle - temp, middle + temp));
        }

        sort(arr.begin(), arr.end(), compare);

        // for(int i =0; i < arr.size(); i++)
        //     printf("%lf %lf\n", arr[i].first, arr[i].second);

        int result = 0;
        double front = 0;

        for(int i = 0; i < arr.size(); i++) {
            if (front >= l) break;

            if (arr[i].first <= front) {
                result++;

                // check for bigger circle
                for(int j = i + 1; j < arr.size(); j++) {
                    if (arr[j].first > front) break;
                    if (arr[j].first <= front && arr[j].second > arr[i].second) i = j;
                }

                front = arr[i].second;
            } else {
                result = -1;
                break;
            }
        }

        if (front < l) result = -1;
        printf("%d\n", result);
    }
}