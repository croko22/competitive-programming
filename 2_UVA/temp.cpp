#define TxtIO                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#include <bits/stdc++.h>

using namespace std;

int main()
{
    TxtIO;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, n, p[55], dp[1000][1000];
    while (cin >> l)
    {
        if (l == 0)
            break;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i];

        p[0] = 0;
        p[n + 1] = l;
        memset(dp, 127, sizeof(dp));

        for (int i = n + 1; i >= 0; i--)
        {
            dp[i][i] = dp[i][i + 1] = 0;
            for (int j = i; j <= n + 1; j++)
            {
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + p[j] - p[i]);
            }
        }

        cout << "The minimum cutting is " << dp[0][n + 1] << "." << endl;
    }

    return 0;
}
