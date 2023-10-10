// 344A - Magnets
#define TxtIO                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // TxtIO;
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, g{1}, prev;
    cin >> n >> prev;
    n--;
    while (n--)
    {
        int b;
        cin >> b;
        if (b != prev)
        {
            g++;
            prev = b;
        }
    }

    cout << g << endl;

    return 0;
}