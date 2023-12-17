#include <stdio.h>
#include <vector>
using namespace std;

class video {
    public:
        int index;
        int duration;
        int entertainment;

        video(int dur, int idx) {
            duration = dur;
            index = idx;
        }
};

int main() {
    int count;
    scanf("%d\n", &count);
    while (count--)
    {
        int n, t;
        scanf("%d %d\n", &n, &t);

        int input;
        vector<video> vecVideo;

        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &input);
            vecVideo.push_back(video(input, i + 1));
        }
        
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &input);
            vecVideo[i].entertainment = input;
        }

        int imax = -1;

        for (int i = 0; i < n; i++) {
            video temp = vecVideo[i];
            // printf("%d %d: %d\n", t >= temp.duration, temp.entertainment > vecVideo[imax].entertainment, i);
            if (t >= temp.duration) {
                if (temp.entertainment > vecVideo[imax - 1].entertainment) imax = i + 1;
                if (imax == -1) imax = i + 1;
            }
            t--;
        }

        printf("%d\n", imax);
    }
}