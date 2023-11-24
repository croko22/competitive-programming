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

    int N, G;
    int S, R;
    vector<int> v;
    while (cin >> N >> G)
    {
        v.clear();
        int points = 0;
        while (N--)
        {
            cin >> S >> R;
            if (S > R)
            {
                points += 3;
                continue;
            }
            v.push_back(R - S);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            if (G > v[i])
            {
                G -= (v[i] + 1);
                points += 3;
            }
            else if (G == v[i])
            {
                G -= v[i];
                points++;
            }
        }
        cout << points << endl;
    }

    return 0;
}