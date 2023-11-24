#define TxtIO                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#include <bits/stdc++.h>
using namespace std;

int main()
{
    TxtIO;
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, L, C;
    while (cin >> N >> L >> C)
    {
        int lines = 1, chars = 0;
        while (N--)
        {
            string s;
            cin >> s;
            // cout << s << endl;
            if (chars + s.size() <= C)
            {
                chars += s.size() + 1;
            }
            else
            {
                lines++;
                chars = s.size() + 1;
            }
        }
        cout << (lines + L - 1) / L << endl;
    }

    return 0;
}