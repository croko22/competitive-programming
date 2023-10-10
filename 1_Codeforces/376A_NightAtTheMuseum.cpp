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

    string s;
    auto last = 'a';
    int r{0};
    cin >> s;

    for (auto c : s)
    {
        int l1 = abs(c - last);
        int l2 = 26 - abs(c - last);
        r += min(l1, l2);
        last = c;
    }

    cout << r << endl;

    return 0;
}