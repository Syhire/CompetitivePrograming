#include <stdio.h>
#include <string>

using namespace std;

string solve(string pre, string in)
{
    if (pre.length() <= 1) // base case
        return pre;

    size_t idxRoot = in.find(pre[0]);
    string s1in = in.substr(0, idxRoot);
    string s2in = in.substr(idxRoot + 1);

    // printf("%s %c %s\n", s1in.c_str(), pre[0], s2in.c_str()); // inorder

    string s1pre = pre.substr(1, s1in.length());
    string s2pre = pre.substr(1 + s1in.length());

    // printf("%c %s %s\n", pre[0], s1pre.c_str(), s2pre.c_str()); // preorder

    return solve(s1pre, s1in) + solve(s2pre, s2in) + pre[0];
}

int main()
{
    char in1[30], in2[30];
    while (scanf("%s %s\n", in1, in2) != EOF)
    {
        string pre = in1, in = in2;

        string res = solve(pre, in);

        printf("%s\n", res.c_str());
    }
}