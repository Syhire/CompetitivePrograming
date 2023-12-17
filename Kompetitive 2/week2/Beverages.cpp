#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int numBev, numCase = 1;

    while (scanf("%d", &numBev) != EOF)
    {
        vector<vector<int> > AdjList;
        vector<int> inDeg;
        map<string, int> nameMap;
        map<int, string> revNameMap;
        bool isVisited[110] = {false};
        char input[55], input2[55];

        AdjList.assign(numBev, vector<int>());
        inDeg.assign(numBev, 0);

        for (int i = 0; i < numBev; i++)
        {
            scanf("%s\n", input);
            nameMap[input] = i;
            revNameMap[i] = input;
        }

        int adj;
        scanf("%d\n", &adj);

        for (int i = 0; i < adj; i++)
        {
            scanf("%s %s\n", input, input2);
            AdjList[nameMap[input]].push_back(nameMap[input2]);
            inDeg[nameMap[input2]]++;
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", numCase++);
        queue<int> qBFS;
        bool done = false;

        while (!done)
        {
            done = true;
            // for (int i = 0; i < numBev; i++)
            //     if (inDeg[i] == 0 && !isVisited[i]) {
            //         done = false;
            //         // qBFS.push(i);
            //         isVisited[i] = true;
            //         printf(" %s", revNameMap[i].c_str());

            //         for (int j = 0; j < AdjList[i].size(); j++)
            //         {
            //             inDeg[AdjList[i][j]]--;
            //         }

            //         i = -1;
            //     }

            for (int i = 0; i < numBev; i++)
                if (inDeg[i] == 0 && !isVisited[i]) {
                    done = false;
                    qBFS.push(i);
                    break;
                }

            while (!qBFS.empty())
            {
                int index = qBFS.front();
                qBFS.pop();

                if (isVisited[index])
                    continue;
                isVisited[index] = true;
                printf(" %s", revNameMap[index].c_str());
                // printf("- %s\n", revNameMap[index].c_str());

                for (int i = 0; i < AdjList[index].size(); i++)
                {
                    inDeg[AdjList[index][i]]--;
                }

                for(int i = 0; i < numBev; i++) {
                    if (inDeg[i] == 0 && !isVisited[i]) {
                        qBFS.push(i);
                        break;
                    }
                }
            }
        }
        printf(".\n\n");
    }
}